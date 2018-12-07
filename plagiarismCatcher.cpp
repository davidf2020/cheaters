//
//  plagiarismCatcher.cpp
//  
//
//  Created by David Fernandez on 12/6/18.
//

#include "plagiarismCatcher.hpp"
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct hashNode {
    int index;
    struct hashNode *next;
};

struct outNode{
    int collisions;
    string file1;
    string file2;
};

int getdir (string dir, vector<string> &files);
int hashKey(string chunk, int HSIZE);
bool compare(outNode i, outNode j);


int main(int argc, char *argv[]) {

    static const int TABLESIZE = 1000003;
    int numWords = 6;
//    int numWords = argv[3];

    hashNode *arr[TABLESIZE];

    for(int i = 0; i < TABLESIZE; i++){
        arr[i] = NULL;
    }

    //////READ IN FILES AND HASH///////////

//    char dir = argv []
    string dir = string("sm_doc_set");          //name directory to with files to hash
    vector<string> files = vector<string>();    //create vector for files to hash

    getdir(dir, files);
    files.erase(files.begin(), files.begin()+2);

    string PATH = "/Users/davidfernandez/EE312/plagiarismCatcher/cmake-build-debug/sm_doc_set/"; //set file path to dir

    vector<string> words = vector<string>();        //vector for all words in file
    vector<string> nwords = vector<string>();       //vector for set of n words in a files
    string addwords;                                //string used to concatenate words to nword chunks

    for (int i = 0; i < files.size(); i++) {        //read in all words from each file and hash to hashTable
        nwords.clear();
        words.clear();                              //clears vector for new file
        cout << i << " "<< files[i] << endl;

        string word;

        string file = PATH + files[i];
        ifstream currentFile(file);

        if (currentFile.is_open()) {
            cout << "File opened." << endl;
            while (currentFile >> word) {
                words.push_back(word);
            }
        } else {
            cout << "File NOT opened." << endl;
        }

        currentFile.close();

        for (int j = 0; (j + numWords) < words.size(); j++) {     //concatenate to nword chunks
            addwords = "";
            for (int k = 0; k < numWords; k++) {
                addwords += words[j + k];
            }
            nwords.push_back(addwords);
        }

        cout << i << "  " <<nwords.size() << endl;

        for (int j = 0; j < nwords.size(); j++) {                            //removes punctuation and capitals
            for (int k = 0, length = nwords[j].size(); k < length; k++) {

                if (nwords[j][k] <= 0x5A && nwords[j][k] >= 0x40) {
                    nwords[j][k] = nwords[j][k] + 0x20;
                }

                if (!((nwords[j][k] >= 0x61 && nwords[j][k] <= 0x7A) || (nwords[j][k] >=0x30 && nwords[j][k] <= 0x39))) {
                    nwords[j].erase(k--, 1);
                    length = nwords[j].size();
                }
            }
        }

        for (int j = 0; j < nwords.size(); j++) {         //prints nword chunks to console
            cout << nwords[j] << "  ";

            int keyIndex = hashKey(nwords[j], TABLESIZE);

            cout << keyIndex << endl;

            if(arr[keyIndex] == NULL){
                hashNode *temp = new hashNode;
                temp->index = i;
                temp->next = NULL;
                arr[keyIndex] = temp;
            }else if(arr[keyIndex]->index != i){
                hashNode *temp = new hashNode;
                temp->index = i;
                temp->next = arr[keyIndex];
                arr[keyIndex] = temp;
            }

//           cout << keyIndex << " for: " << nwords[j] << endl;

        }

    }

    static const int rcSize = files.size();

    int gridC[rcSize][rcSize];          //grid of all the collisons

    for(int i=0; i<(rcSize); i++){
        for(int j=0; j<(rcSize); j++){
            gridC[i][j] = 0;
        }
    }

////USED TO CHECK the CLEARING of GRID///////////

//    for(int i=0; i<(rcSize); i++){
//        for(int j=0; j<(rcSize); j++){
//            cout << gridC[i][j] << " ";
//        }
//        cout << endl;
//    }

    for(int i=0; i < TABLESIZE-1; i++){
        hashNode *first = arr[i];
        hashNode *second;
//        hashNode *row;
//        hashNode *col;

        if(first != NULL) {
            second = first->next;
        }

        if (arr[i] != NULL){
            while(first != NULL){
                while(second!=NULL){
                    gridC[second->index][first->index] += 1;
                    second = second->next;
                }
                second = first -> next;
                first = second;

                if(second != NULL){
                    second = second->next;
                }
            }
        }
    }


///////USED TO CHECK COLLISIONS ON GRID///////

//    for(int i=0; i<(rcSize); i++){
//        for(int j=0; j<(rcSize); j++){
//            cout << gridC[i][j] << "  ";
//        }
//        cout << endl;
//    }

    vector<outNode> output;


    for(int i = 0; i < rcSize; i++){
        for(int j = 0; j < rcSize; j++){
            if(gridC[i][j] > 100){
                outNode newOut;
                newOut.collisions = gridC[i][j];
                newOut.file1 = files[i];
                newOut.file2 = files[j];

                output.push_back(newOut);
            }
        }
    }

    sort(output.begin(), output.end(), compare);

    for(vector<outNode>::iterator iter = output.begin(); iter != output.end(); iter++){
        cout<< iter->collisions << " " << iter->file1 << " " << iter->file2 << endl;
    }


}



int getdir(string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}



    int hashKey(string chunk, int HSIZE){

       unsigned int keyIndex = 0;

        for (int i = 0; i < chunk.size() - 1; i++) {

            double index2 = chunk[chunk.size() - i - 1];

            double nindex = index2;

            nindex = nindex * pow(31.0, i);

            index2 = (unsigned int) nindex;

            keyIndex += index2;

        }

        keyIndex = keyIndex % HSIZE;

        return keyIndex;

    }

bool compare(outNode i, outNode j){
    if(i.collisions>j.collisions){
        return true;
    }else{
        return false;
    }
}
