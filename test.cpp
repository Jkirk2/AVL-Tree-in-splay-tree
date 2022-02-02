#include <iostream>
#include "wordTree.h"
using namespace std;
int main(){
    auto wt = WordTree();
    auto wt2 = WordTree();
    auto wt3 = WordTree();
    string alphabet[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

    for(int i = 0; i < 26; i++){
        wt.insert(alphabet[i]);

    }
    cout << "Added the entire alphabet to the tree" << endl;
    wt.dump();
    cout << endl;

    cout << endl << "---------Node heights for each letter-----------" << endl;
    for(int i = 0; i < 26; i++){
        cout << alphabet[i] << ": " << wt.getNodeHeight(alphabet[i]) << endl;
    }
    cout << endl << "---------Amount of steps to search for each letter-----------" << endl;
    for(int i = 0; i < 26; i++){

        cout << alphabet[i] << ": " << wt.searchCount(alphabet[i]) << endl;
        if(wt.searchCount(alphabet[i]) == -1){
            throw out_of_range("Letter not in the tree");
        }
    }

    cout << " --------------Testing every third letter----------------------" << endl;

    for(int i = 0; i < 26; i+=3){
        wt2.insert(alphabet[i]);

    }
    cout << "Added every third letter to the tree" << endl;
    wt2.dump();
    cout << endl;

    cout << endl << "---------Node heights for each letter-----------" << endl;
    for(int i = 0; i < 26; i+=3){
        cout << alphabet[i] << ": " << wt2.getNodeHeight(alphabet[i]) << endl;
    }
    cout << endl << "---------Amount of steps to search for each letter-----------" << endl;
    for(int i = 0; i < 26; i+=3){

        cout << alphabet[i] << ": " << wt2.searchCount(alphabet[i]) << endl;
        if(wt2.searchCount(alphabet[i]) == -1){
            throw out_of_range("Letter not in the tree");
        }
    }

    cout << " --------------Testing every third letter backwards than every letter forwards----------------------" << endl;

    for(int i = 25; i > -1; i-=3){
        wt3.insert(alphabet[i]);
    }
    cout << endl;
    for(int i = 0; i < 26; i++){
        wt3.insert(alphabet[i]);

    }
    cout << "Added every letter backwards and every third letter forwards" << endl;
    wt3.dump();
    cout << endl;

    cout << endl << "---------Node heights for each letter-----------" << endl;
    for(int i = 0; i < 26; i++){
        cout << alphabet[i] << ": " << wt3.getNodeHeight(alphabet[i]) << endl;
        if(wt3.searchCount(alphabet[i]) == -1){
            cout << alphabet[i] << " NOT IN TREE" << endl;
        }
    }
    cout << endl << "---------Amount of steps to search for each letter-----------" << endl;
    for(int i = 0; i < 26; i++){

        cout << alphabet[i] << ": " << wt3.searchCount(alphabet[i]) << endl;
        if(wt3.searchCount(alphabet[i]) == -1){
            cout << alphabet[i] << " NOT IN TREE" << endl;
        }
    }
    cout << endl << "---------checking number of occurrences and find function-----------" << endl;
    for(int i = 0; i < 26; i++){

        cout << alphabet[i] << ": " << wt3.find(alphabet[i])->getFrequency() << endl;
        if(wt3.searchCount(alphabet[i]) == -1){
            cout << alphabet[i] << " NOT IN TREE" << endl;
        }
    }

    cout << "testing double left rotation" << endl;

    auto wt6 = WordTree();
    wt6.insert("a");
    wt6.insert("f");
    wt6.insert("b");

    wt6.dump();

    cout << endl << "testing double right rotation" << endl;

    auto wt5 = WordTree();
    wt5.insert("f");
    wt5.insert("a");
    wt5.insert("d");

    wt5.dump();

    cout << endl << "All search and rotation tests passed" << endl;

    auto wt7 = WordTree();

    return 0;
}
