//
// Created by dimitrisgan on 4/3/2019.
//

#include "synchroniseFunctions.h"


//Synchroniser sync (&senderHT,&receiverHT,&walletHT,&btcHT ,&transacHT); //initiate sync struct




void Synchroniser::insertTransaction(transaction potentialTransaction) {

    //todo [DONE]1#  koitaw apo senders wallet an exei to apaitoumeno poso
    //todo [DONE]2#  an oxi :exit()
    //todo 3#  an nai sortarw an goustarw apo th lista me ta btc kai anoigw auta me to megalutero poso
    //todo 4#  paw sta dentra twn chosenBtc kai ta skavw ---> ta xwnw se mia lista kai to poso pou phra ---> ta xwnw sto transaction mou (forse pointer)
    //todo 5#  sto skapsimo h sunarthsh prepei na mou epistrepsei pointers (stous pateres) sta kainourgia nodes pou anoiksa
    //todo 6#  autous tous pointers tous xwnw sto potentialTransaction.treeNodeList_ptrs<t_nodes*>.PROSOXH! xwnw to aristero paidi ston sender kai deksi sto wallet
    //todo edw dhmiourgeitai h aporia mhpws prepei na xw sa parametro 2 transacNodes --> ena tou sender kai ena tou receiver


    wallet  *sendersWallet =  this->walletHT_ptr.getData(potentialTransaction.getSenderWalletId());


    if (!transactionIsValid(potentialTransaction, sendersWallet->getBalance())){ //check id transaction is possible or throw error and exit
        std::cerr << "CANT APPLY THE TRANSACTION WITH ID# "<<potentialTransaction.getTransacId()<<endl;
        exit(NOT_VALID_TRSANSACTION);
    }
    //transaction is valid
    //todo apo sender pairnw to poso kai to tsekarw apo ta t-nodes
    linkedList<myString> btcId2extract_list;
    linkedList<int> amountInEachBtc2extract_list;
    linkedList<int> indexesThatSenderLostBtcOwnership;

    int amount2extract = potentialTransaction.getAmount();


    decideWhichAndHowMuchInEach2extractFromSender(sendersWallet, btcId2extract_list, amountInEachBtc2extract_list,
                                                  amount2extract, indexesThatSenderLostBtcOwnership);

    removeLostOwnershipBtcFromSender (sendersWallet , indexesThatSenderLostBtcOwnership);

    cout << "EXIT 1000\n";

    exit(4);
    //todo tha to valw sto telos afou exw setarei kai th lista pou tha dwsei
//    this->transacHT_ptr.insert(potentialTransaction.transacId, potentialTransaction);




    //todo last#  kanw update ta upoloipo--btcList--amountBtcList sta wallets tou sender kai receiveer


    cout << "exit apo edw \n";

}


void Synchroniser::decideWhichAndHowMuchInEach2extractFromSender(wallet *sendersWallet,
                                                                 linkedList<myString> &btcId2extract_list,
                                                                 linkedList<int> &amountInEachBtc2extract_list,
                                                                 int amount2extract,
                                                                 linkedList<int> &indexesList2remove) {


    int amountRemain2gather =amount2extract;
//    for ( auto &item : sendersWallet->getAmountOnEachBtc()) {
//        if (item < amountRemain2gather){
//            //todo tha to parei olo
//
//        }
//    }


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

//            sendersWallet..deleteNodeByIndex(index);
//            sendersWallet->getBtcIdsOwned_list().(*ItA);
            break;

        }
        else { //means that the wallet will give all his onwership to this btc
            amountRemain2gather -= *ItB;

            btcId2extract_list.insert_last(*ItA); //add btcId in exchange list
            amountInEachBtc2extract_list.insert_last(*ItB);
            sendersWallet->setBalance(sendersWallet->getBalance() - *ItB); //update the new total baalnce

            indexesList2remove.insert_last(index);
            *ItB = 0; //the wallet(=sender) is not owner of this btc anymore
            //todo do the appropriate removes for the senders 2 lists!!!!!!!!!!!!!!!!!!!!!!!

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
        if(ItA == sendersWallet->getBtcIdsOwned_list().end() && ItB == sendersWallet->getAmountOnEachBtc().end())
        {
            break;
        }
    }
}


Synchroniser::Synchroniser(const myTransacHashMap &senderHT_ptr, const myTransacHashMap &receiverHT_ptr,
                           const myHashMap<wallet> &walletHT_ptr, const myHashMap<bitcoin> &btcHT_ptr,
                           const myHashMap<transaction> &transacHT_ptr) : senderHT_ptr(senderHT_ptr),
                                                                          receiverHT_ptr(receiverHT_ptr),
                                                                          walletHT_ptr(walletHT_ptr),
                                                                          btcHT_ptr(btcHT_ptr),
                                                                          transacHT_ptr(transacHT_ptr) {}


bool Synchroniser::transactionIsValid(transaction potentialTransac, int sendersBalance) {
    return (potentialTransac.getAmount() <= sendersBalance);
}


void Synchroniser::removeLostOwnershipBtcFromSender (wallet *sendersWallet , linkedList<int>  &indexesThatSenderLostBtcOwnership){

    bool flagError =false;
    for (const auto &item : indexesThatSenderLostBtcOwnership) {

        flagError= sendersWallet->getBtcIdsOwned_listByRef().deleteNodeByIndex(item);
        flagError= sendersWallet->getAmountOnEachBtcByRef().deleteNodeByIndex(item);
    }
    if (flagError){
        std::cerr << "ERROR IN DELETION  "<<endl;
        exit(1);
    }

}



//            this->walletHT_ptr.getData(potentialTransac.getSenderWalletId()).getBalance());


