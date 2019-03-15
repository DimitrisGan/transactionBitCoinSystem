//
// Created by dimitrisgan on 4/3/2019.
//

#include "synchroniser.h"
#include "assistantFunctions.h"



void Synchroniser::insertTransaction(transaction potentialTransaction) {


    wallet  *sendersWallet =  this->walletHT_ptr->getData(potentialTransaction.getSenderWalletId());
    wallet  *receiversWallet =  this->walletHT_ptr->getData(potentialTransaction.getReceiverWalletId());

//todo check if sender/receiver wallet    this->walletHT_ptr.exists(sendersWallet->getId() ,sendersWallet);

    if (! this->walletHT_ptr->exists(sendersWallet->id) ){
        std::cerr << "CANT APPLY THE TRANSACTION  ID# "<<potentialTransaction.getTransacId()<<" BECAUSE SENDER WITH ID# "<<potentialTransaction.senderWalletId <<" DOESNT EXIST"<<endl;
        exit(NOT_VALID_TRSANSACTION);
    }

    if (! this->walletHT_ptr->exists(receiversWallet->id) ){
        std::cerr << "CANT APPLY THE TRANSACTION  ID# "<<potentialTransaction.getTransacId()<<" BECAUSE RECEIVER WITH ID# "<<potentialTransaction.receiverWalletId <<" DOESNT EXIST"<<endl;
        exit(NOT_VALID_TRSANSACTION);
    }

    if (potentialTransaction.getSenderWalletId() == potentialTransaction.getReceiverWalletId()){ //check if user is the same and sends to himself money
        std::cerr << "CANT APPLY THE TRANSACTION WITH ID# "<<potentialTransaction.getTransacId()<< " BECAUSE THE RECEIVER IS ALSO THE SENDER WITH ID# "<<potentialTransaction.receiverWalletId<<endl;
        exit(NOT_VALID_TRSANSACTION);
    }


    if (!transactionIsValid(potentialTransaction, sendersWallet->getBalance())){ //check id transaction is possible or throw error and exit
        std::cerr << "CANT APPLY THE TRANSACTION WITH ID# "<<potentialTransaction.getTransacId()<< " BECAUSE THERE IS NOT ENOUGH BALANCE FROM SENDER"<<endl;
        exit(NOT_VALID_TRSANSACTION);
    }

    //transaction is valid

    linkedList<myString> btcId2extract_list;
    linkedList<int> amountInEachBtc2extract_list;
    linkedList<myString> btcIds2deleteFromOwner;

    int amount2extract = potentialTransaction.getAmount();


    decideWhichAndHowMuchInEach2extractFromSender(sendersWallet, btcId2extract_list, amountInEachBtc2extract_list,
                                                  amount2extract, btcIds2deleteFromOwner);

    removeLostOwnershipBtcFromSender (sendersWallet , btcIds2deleteFromOwner);

    addAmountAndBtc2receiver(receiversWallet , btcId2extract_list ,amountInEachBtc2extract_list);


    addTheNewNodes2Tree(potentialTransaction , btcId2extract_list ,amountInEachBtc2extract_list);


    this->transacHT_ptr->insert(potentialTransaction.transacId , potentialTransaction); //insert new transaction in the transactionHT

    this->transacHT_ptr->getData(potentialTransaction.transacId)->updateTransacionPtrIn_t_nodes();  //here we do the update to the t_nodes ptrs to transactions

    //insert the transaction ptr to senderHT
    this->senderHT_ptr->addTransacNode2appropriateIndex(potentialTransaction.senderWalletId , this->transacHT_ptr->getData(potentialTransaction.transacId) ); //insert a new node with a pointer to the transaction node in senderHT
    //insert the transaction ptr to receiverHT
    this->receiverHT_ptr->addTransacNode2appropriateIndex(potentialTransaction.receiverWalletId , this->transacHT_ptr->getData(potentialTransaction.transacId) ); //insert a new node with a pointer to the transaction node in receiverHT


    this->updateMaxId(potentialTransaction.transacId);
    this->updateLatestDate(potentialTransaction.transacTime);


    cout <<"[success] transaction with id# "<<potentialTransaction.transacId <<" added! "<<endl;


}



void Synchroniser::decideWhichAndHowMuchInEach2extractFromSender(wallet *sendersWallet,
                                                                 linkedList<myString> &btcId2extract_list,
                                                                 linkedList<int> &amountInEachBtc2extract_list,
                                                                 int amount2extract,
                                                                 linkedList<myString> &indexesList2remove) {

    int amountRemain2gather =amount2extract;

    linkedList<myString>::Iterator  ItA;
    linkedList<int>::Iterator  ItB;

    assert(sendersWallet->getBtcIdsOwned_list().getSize() == sendersWallet->getAmountOnEachBtc().getSize());



    ItA = sendersWallet->getBtcIdsOwned_listByRef().begin();
    ItB = sendersWallet->getAmountOnEachBtcByRef().begin();
    /*
     * ItA = btcId name
     * ItB = amount owned of the current btc
     **/
    int index =0; //maybe is needed to deleteByIndex if a btc to senders wallet reached zero
    while(true) //iterate simultaneously the 2 lists
    {

        //do stuff with ItA and ItB

        if (*ItB >= amountRemain2gather){ //means that the percentage amount of this btc is bigger than the remain2extract
            btcId2extract_list.insert_last(*ItA);
            amountInEachBtc2extract_list.insert_last(amountRemain2gather);

            *ItB = *ItB - amountRemain2gather; //reduce the amount from the owner(=sender) wallet
            sendersWallet->setBalance(sendersWallet->getBalance() - amountRemain2gather); //update the new total baalnce
            amountRemain2gather=0;

            break;

        }
        else { //means that the wallet will give all his onwership to this btc
            amountRemain2gather -= *ItB;

            btcId2extract_list.insert_last(*ItA); //add btcId in exchange list
            amountInEachBtc2extract_list.insert_last(*ItB);
            sendersWallet->setBalance(sendersWallet->getBalance() - *ItB); //update the new total baalnce

            indexesList2remove.insert_last(*ItA);
            *ItB = 0; //the wallet(=sender) is not owner of this btc anymore

        }


        index++;

        if(ItA != sendersWallet->getBtcIdsOwned_list().end())
        {
            ++ItA;
        }
        if(ItB != sendersWallet->getAmountOnEachBtc().end())
        {
            ++ItB;
        }
//        if(ItA == sendersWallet->getBtcIdsOwned_list().end() && ItB == sendersWallet->getAmountOnEachBtc().end())
//        {
//            break;
//        }
    }
}



bool Synchroniser::transactionIsValid(transaction potentialTransac, int sendersBalance) {
    return (potentialTransac.getAmount() <= sendersBalance);
}


void Synchroniser::removeLostOwnershipBtcFromSender(wallet *sendersWallet, linkedList<myString> &btc2deleteInlist){

    bool flagError =false;
    for ( auto &item : btc2deleteInlist) {

        flagError= sendersWallet->getBtcIdsOwned_listByRef().deleteNodeByItem(item);
        flagError= sendersWallet->getAmountOnEachBtcByRef().deleteNodeByItem(0); //delete the nodes that have zero as amount
    }
    if (flagError){
        std::cerr << "ERROR IN DELETION "<<endl;
        exit(DELETION);
    }

}

void Synchroniser::addAmountAndBtc2receiver(wallet *receiversWallet, linkedList<myString> btcId2extract_list,
                                            linkedList<int> amountInEachBtc2extract_list) {



    int index2increse = 0;
    int sumBalancies= receiversWallet->getBalance();
//    if (! receiversWallet->getBtcIdsOwned_list().isEmpty()) {
    for (auto &btcId : btcId2extract_list) {

        int amount2insert = amountInEachBtc2extract_list.getByIndex(index2increse)->getData();

        sumBalancies+=amount2insert;

        if (receiversWallet->btcExists(btcId) ){ //it means that in the current btc btcReceiver has already percentage so we have oly to increase the amount and not add new btc
            //then we have to update already existing amount

            int index2update = receiversWallet->getIndexBybtcId(btcId);

            int existingAmount = receiversWallet->getAmountOnEachBtc().getByIndex(index2update)->getData();
            assert(index2update >=0);

            int newTotalAmount = existingAmount + amount2insert ;

            receiversWallet->updateAmountByIndex(index2update,newTotalAmount);


        }
        else{ //we have to insrt the new btc and its amount
            receiversWallet->getBtcIdsOwned_listByRef().insert_last(btcId);
            receiversWallet->getAmountOnEachBtcByRef().insert_last(amount2insert);

        }




        index2increse++;
    }

    receiversWallet->setBalance(sumBalancies); //update the new total baalnce



}

void Synchroniser::addTheNewNodes2Tree(transaction &potentialTransaction , linkedList<myString> btcId2extract_list ,linkedList<int> amountInEachBtc2extract_list)
{


    linkedList<myString>::Iterator  ItA;
    linkedList<int>::Iterator  ItB;

    ItA = btcId2extract_list.begin();           //refers to the btcIds
    ItB = amountInEachBtc2extract_list.begin(); //refers to the amount to extract from each btc


    int counter=0;
    while(true) //iterate simultaneously the 2 lists
    {
//        if (btcId2extract_list.isEmpty() ) {break;}
        if (counter == amountInEachBtc2extract_list.getSize()){break;ItA= nullptr;ItB= nullptr;}


        //do stuff with ItA and ItB
        int amount = *ItB;
        myString btcId= *ItA;
        this->btcHT_ptr->getData(btcId)->getTransactionTree_ptr()->insert(potentialTransaction.getSenderWalletId() , potentialTransaction.getReceiverWalletId() , amount ,potentialTransaction.t_nodePtrList);


        counter++;


        if (ItA != btcId2extract_list.end()) {
            ++ItA;
        }
        if (ItB != amountInEachBtc2extract_list.end()) {
            ++ItB;
        }
//        if (ItA == btcId2extract_list.end() && ItB == amountInEachBtc2extract_list.end()) {
//            break;
//        }


    }


}

Synchroniser::Synchroniser(myTransacHashMap *senderHT_ptr, myTransacHashMap *receiverHT_ptr,
                           myHashMap<wallet> *walletHT_ptr, myHashMap<bitcoin> *btcHT_ptr,
                           myHashMap<transaction> *transacHT_ptr) : senderHT_ptr(senderHT_ptr),
                                                                    receiverHT_ptr(receiverHT_ptr),
                                                                    walletHT_ptr(walletHT_ptr), btcHT_ptr(btcHT_ptr),
                                                                    transacHT_ptr(transacHT_ptr) ,max_t_id(0){}

myTransacHashMap *Synchroniser::getSenderHT_ptr() const {
    return senderHT_ptr;
}

myTransacHashMap *Synchroniser::getReceiverHT_ptr() const {
    return receiverHT_ptr;
}

myHashMap<wallet> *Synchroniser::getWalletHT_ptr() const {
    return walletHT_ptr;
}

myHashMap<bitcoin> *Synchroniser::getBtcHT_ptr() const {
    return btcHT_ptr;
}

myHashMap<transaction> *Synchroniser::getTransacHT_ptr() const {
    return transacHT_ptr;
}

const date &Synchroniser::getLatestTrsansactionDate() const {
    return latestTransacDate;
}



void Synchroniser::updateMaxId(myString id) {


    if (isNumber(id.getMyStr())){ //check if given id is number
        int number = atoi (id.getMyStr());
        if (number > this->max_t_id)
            this->max_t_id = number;
        else if (number == this->max_t_id)
            assert(1);
    }

}

myString Synchroniser::createVirtualTransacId() {
    int newId = this->max_t_id + 1;
    char str[10];

    sprintf(str, "%d", newId);// Now str contains the integer as characters
    myString virtualId (str);
    return virtualId;
}

void Synchroniser::updateLatestDate(date newDate) {

    if (this->latestTransacDate.isNull())
        this->latestTransacDate = newDate;
    else{
        if (newDate >= this->latestTransacDate) //if the new transaction date is the latest then assign it to sync class attribute
            this->latestTransacDate = newDate;
        else{
            if (this->latestTransacDate > newDate){
                std::cerr << "CANT APPLY THE TRANSACTION BECAUSE THE DATE IS ANTECEDENT TO THE LATEST TRANSACTION "<<endl;
                std::cerr << "LATEST DATE : "<<this->latestTransacDate<<endl;
                std::cerr << "NOT VALID TRANSACTION DATE : "<<newDate<<endl;
                exit(NOT_VALID_TRSANSACTION);
            }
        }
    }
}



