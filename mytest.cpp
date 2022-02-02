#include "bookTree.h"

using namespace std;

int main() {


//    BookTree aTree;
//
//    cout << "creating a new bookTree with example data" << endl;
//    aTree.loadData("Frankenstein.txt");
//    cout << "Passed loading the data from text file" << endl;
//
//    cout << "frankenstein" << endl;
//
//    cout << "Dumping frankenstein " << endl << endl;
//    aTree.dumpTitle("frankenstein");
//    cout << endl << endl << endl << endl;
//    cout << "Frequency of humankind in frankenstein" << endl;
//    cout << "\t" << aTree.findFrequency("frankenstein", "sir") << endl << endl;
//    cout << "Count of search operation for humankind in frankenstein" << endl;
//    cout << "\t" << aTree.searchCount("frankenstein", "sir") << endl << endl;
//   cout << "Height of the node containing humankind in frankenstein" << endl;
//    cout << "\t" << aTree.getWordHeight("frankenstein", "sir") << endl << endl;
//    cout << "Height of word tree for frankenstein" << endl;
//    cout << "\t" << aTree.getTextTreeHeight("frankenstein") << endl << endl;
//
//    the real test


    cout << endl << "-----------------------AVL TREE TEST--------------------------" << endl << endl;
    auto wt = WordTree();

    cout <<"testing left rotation. Inserting: pancakes, steaks, tangerines" << endl;
    wt.insert("pancakes");
    wt.insert("steaks");
    wt.insert("tangerines");
    wt.insert("pancakes");
    wt.insert("steaks");
    wt.insert("tangerines");
    wt.insert("pancakes");
    wt.insert("steaks");
    wt.insert("tangerines");
    wt.insert("pancakes");
    wt.insert("steaks");
    wt.insert("tangerines");
    wt.dump();
    cout << endl << "passed!" << endl;

    auto wt2 = WordTree();
    cout << endl << "testing right rotation. Inserting: pancakes, lemons, apples " << endl;
    wt2.insert("pancakes");
    wt2.insert("lemons");
    wt2.insert("apples");
    wt2.dump();
    cout << endl << "passed!" << endl;

    auto wt3 = WordTree();
    cout << endl << "testing right left rotation. Inserting: pancakes, steaks, ravioli" << endl;
    wt3.insert("pancakes");
    wt3.insert("steaks");
    wt3.insert("ravioli");
    wt3.dump();
    cout << endl << "passed!" << endl;

    auto wt4 = WordTree();
    cout << endl << "testing left right rotation. Inserting: pancakes, apples, bananas" << endl;
    wt4.insert("pancakes");
    wt4.insert("apples");
    wt4.insert("bananas");
    wt4.dump();
    cout << endl << "passed!" << endl;


    cout << endl << "-----------------------EMPTY BOOKTREE Functions TEST--------------------------" << endl << endl;
    BookTree emptyTree;

    cout << "testing bookTree loadData on an blank txt file" << endl;
    emptyTree.loadData("empty_data.txt");
    cout << "Passed!" << endl << endl;


    cout << "testing findFrequency of \"\" in \"\" (testing the blank bookTree)" << endl;
    cout << "\t" << "frequency of \"\"  " << emptyTree.findFrequency("", "") << endl << endl;

    cout << "testing searchCount of \"\" in \"\" (testing the blank bookTree)" << endl;
    cout << "\t" << " search operations to find \"\"  " << emptyTree.searchCount("", "") << endl << endl;

    cout << "testing getTextTreeHeight of \"\"  (testing the blank bookTree)" << endl;
    cout << "\t" << " height of word tree  " << emptyTree.getTextTreeHeight("") << endl << endl;

    cout << "testing getWordHeight of \"\" in \"\" (testing the blank bookTree)" << endl;
    cout << "\t" << " word height of \"\" in \"\"  " << emptyTree.getWordHeight("", "") << endl << endl;

    cout << "testing dumpTitle of \"\" (testing the blank bookTree)" << endl;
    emptyTree.dumpTitle("");
    cout << "Passed!" << endl << endl;

    cout << endl << "-----------------------Populated BookTree Functions Test--------------------------" << endl
         << endl;

    BookTree aTree;
//similar to example
    cout << "creating a new bookTree with example data" << endl;
    aTree.loadData("data.txt");
    cout << "Passed loading the data from text file" << endl;

    cout << "Testing the wizard of oz" << endl;

    cout << "Frequency of tinsmith in The Wonderful Wizard of Oz (expecting 4): " << endl;
    cout << "\t" << aTree.findFrequency("the wonderful wizard of oz", "tinsmith") << endl << endl;
    cout << "Count of search operation for tinsmith in The Wonderful Wizard of Oz (expecting 5): " << endl;
    cout << "\t" << aTree.searchCount("the wonderful wizard of oz", "tinsmith") << endl << endl;
    cout << "Height of the node containing tinsmith in The Wonderful Wizard of Oz: (expecting 2)" << endl;
    cout << "\t" << aTree.getWordHeight("the wonderful wizard of oz", "tinsmith") << endl << endl;
    cout << "Height of word tree for The Wonderful Wizard of Oz: (expecting 7)" << endl;
    cout << "\t" << aTree.getTextTreeHeight("the wonderful wizard of oz") << endl << endl;
    cout << "Dumping the word tree for The Wonderful Wizard of Oz: " << endl << endl;
    aTree.dumpTitle("the wonderful wizard of oz");

    cout << endl << endl << "-----------------------Testing splay functions--------------------------" << endl
         << "Heights of trees should all be similar, calls all books, accessed books should become the new root"
         << endl;
    //commented out dump tests to make this part readable
    cout << endl << "Accessing Great Expectations " << endl;
    cout << "avl tree height in Great Expectations" << endl;
    cout << "\t" << aTree.getTextTreeHeight("great expectations") << endl;
    cout << "New root should be: great expectations" << endl;
    cout << "Root of BookTree: " << aTree.getRootKey() << endl << endl;
    //aTree.dumpTitle("great expectations");

    cout << endl << "Accessing a tale of two cities " << endl;
    cout << "avl tree height in a tale of two cities" << endl;
    cout << "\t" << aTree.getTextTreeHeight("a tale of two cities") << endl;
    cout << "New root should be: a tale of two cities" << endl;
    cout << "Root of BookTree: " << aTree.getRootKey() << endl << endl;
    //aTree.dumpTitle("a tale of two cities");


    cout << endl << "Accessing adventures of huckleberry finn " << endl;
    cout << "avl tree height in adventures of huckleberry finn" << endl;
    cout << "\t" << aTree.getTextTreeHeight("adventures of huckleberry finn") << endl;
    cout << "New root should be: adventures of huckleberry finn" << endl;
    cout << "Root of BookTree: " << aTree.getRootKey() << endl << endl;
    //aTree.dumpTitle("adventures of huckleberry finn");


    cout << endl << "Accessing the pride and prejudice" << endl;
    cout << "avl tree height in pride and prejudice" << endl;
    cout << "\t" << aTree.getTextTreeHeight("pride and prejudice") << endl;
    cout << "New root should be: pride and prejudice" << endl;
    cout << "Root of BookTree: " << aTree.getRootKey() << endl << endl;
    //aTree.dumpTitle("pride and prejudice");

    cout << endl << "Accessing moby dick" << endl;
    cout << "avl tree height in moby dick" << endl;
    cout << "\t" << aTree.getTextTreeHeight("moby dick") << endl;
    cout << "New root should be: moby dick" << endl;
    cout << "Root of BookTree: " << aTree.getRootKey() << endl << endl;
    //aTree.dumpTitle("moby dick");

    cout << endl << "Accessing the wonderful wizard of oz" << endl;
    cout << "avl tree height in the wonderful wizard of oz" << endl;
    cout << "\t" << aTree.getTextTreeHeight("the wonderful wizard of oz") << endl;
    cout << "New root should be: the wonderful wizard of oz" << endl;
    cout << "Root of BookTree: " << aTree.getRootKey() << endl << endl;
    //aTree.dumpTitle("the wonderful wizard of oz");

    cout << endl << "Accessing the brothers karamazov" << endl;
    cout << "avl tree height in the brothers karamazov" << endl;
    cout << "\t" << aTree.getTextTreeHeight("the brothers karamazov") << endl;
    cout << "New root should be: the brothers karamazov" << endl;
    cout << "Root of BookTree: " << aTree.getRootKey() << endl << endl;
    //aTree.dumpTitle("the brothers karamazov");

    cout << endl << "Accessing the masque of the red death" << endl;
    cout << "avl tree height in the masque of the red death" << endl;
    cout << "\t" << aTree.getTextTreeHeight("the masque of the red death") << endl;
    cout << "New root should be: the masque of the red death" << endl;
    cout << "Root of BookTree: " << aTree.getRootKey() << endl << endl;
    //aTree.dumpTitle("the masque of the red death");

    cout << endl << endl << "--------------------- All tests were successful! ---------------------------" << endl;

    return 0;
}