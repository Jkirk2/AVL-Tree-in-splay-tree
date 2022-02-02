#include "bookTree.h"

BookTree::BookTree() {

    _root = nullptr;
}

BookTree::~BookTree() {
    clear(_root);
    if (_root != nullptr) {
        delete _root;
    }
}

BNode *BookTree::makeSplay(BNode *root, string key) {
    //base case for returning the root
    if (root == _root) {

        return root;
    }
        //calls the different methods of rotation, returns the new root
    else if (key == root->_key) {

        //checks for zig zig and zig zag
        if (root->_parent->_parent != nullptr) {

            //a pointer to the grandparent
            BNode *grandparent = root->_parent->_parent;

            //checks left zig zig
            if (grandparent->_left != nullptr && grandparent->_left->_left == root) {
                //two right rotations, grandparent should become the root

                grandparent = rightRotate(grandparent);
                grandparent = rightRotate(grandparent);


            }
                //checks right zig zig
            else if (grandparent->_right != nullptr && grandparent->_right->_right == root) {
                //two right rotations, grandparent should become the root

                grandparent = leftRotate(grandparent);
                grandparent = leftRotate(grandparent);

            }

                //zig zag right left
            else if (grandparent->_right != nullptr && grandparent->_right->_left == root) {

                grandparent->_right = rightRotate(grandparent->_right);
                grandparent = leftRotate(grandparent);
            }
                //zig zag left right
            else if (grandparent->_left != nullptr && grandparent->_left->_right == root) {

                grandparent->_left = leftRotate(grandparent->_left);
                grandparent = rightRotate(grandparent);
            } else {
                cout << "Splay Failed" << endl;
            }
            return makeSplay(grandparent, key);
        }
            //This does a zig rotation
        else {

            if (_root->_left == root) {

                return makeSplay(rightRotate(_root), key);
            } else if (_root->_right == root) {

                return makeSplay(leftRotate(_root), key);
            } else {
                cout << "Make Splay failed!" << endl;
            }
        }

    }

    cout << "Make Splay failed!" << endl;
    return nullptr;
}

BNode *BookTree::rightRotate(BNode *x) {

    if (x->_left == nullptr) {
        throw out_of_range("Error: Right rotation left node (new root) is non existent (null)");
    }

    //stores the new root
    BNode *leftChild = x->_left;

    if (x->_parent != nullptr) {
        if (x->_parent->_left == x) {
            x->_parent->_left = leftChild;
        } else {
            x->_parent->_right = leftChild;
        }
    }
    //updates the parents of the subnodes
    if (leftChild->_right != nullptr) {
        leftChild->_right->_parent = x;
    }


    //makes the left child of the old root the new roots right child
    x->_left = leftChild->_right;
    //updates the parents

    leftChild->_parent = x->_parent;

    x->_parent = leftChild;
    //Makes the new roots right child the old root finishing the rotation
    leftChild->_right = x;

    //updates the root and its parents;
    if (_root == x) {
        _root = leftChild;
    }
    return leftChild;
}

BNode *BookTree::leftRotate(BNode *x) {
    if (x->_right == nullptr) {
        throw out_of_range("Error: Left rotation left node (new root) is non existent (null)");
    }

    //stores the new root
    BNode *rightChild = x->_right;

    //updating the parent
    if (x->_parent != nullptr) {
        if (x->_parent->_left == x) {
            x->_parent->_left = rightChild;
        } else {
            x->_parent->_right = rightChild;
        }
    }
    if (rightChild->_left != nullptr) {
        rightChild->_left->_parent = x;
    }

    //makes the right child of the old root the new roots left child
    x->_right = rightChild->_left;
    //updates the parents
    rightChild->_parent = x->_parent;
    x->_parent = rightChild;
    //Makes the new roots right child the old root finishing the rotation
    rightChild->_left = x;
    //updates the root

    if (_root == x) {
        _root = rightChild;
    }
    return rightChild;

}

bool BookTree::insert(string key, string author, string text) {

    if (_root == nullptr) {
        BNode *newNode = new BNode(key, author, text);
        _root = newNode;
        return true;
    } else {

        BNode *curNode = _root;
        while (key != curNode->_key && curNode != nullptr) {

            //left
            if (key.compare(curNode->_key) < 0) {


                if (curNode->_left == nullptr) {
                    BNode *newNode = new BNode(key, author, text);

                    curNode->_left = newNode;
                    newNode->_parent = curNode;

                    _root = makeSplay(newNode, key);

                    return true;
                } else {

                    curNode = curNode->_left;

                }
            }
                //right
            else if (key.compare(curNode->_key) > 0) {
                if (curNode->_right == nullptr) {
                    BNode *newNode = new BNode(key, author, text);
                    curNode->_right = newNode;
                    newNode->_parent = curNode;
                    _root = makeSplay(newNode, key);
                    return true;
                } else {

                    curNode = curNode->_right;


                }
            }
        }
    }
    return false;
}

void BookTree::clear(BNode *root) {
    //goes down left until its null
    if (root != nullptr) {
        if (root->_left != nullptr) {
            clear(root->_left);
        }
        //goes down right until its nul
        if (root->_right != nullptr) {
            clear(root->_right);
        }

        //deletes since all subtrees below it have been deleted
        if (root == _root) {
            root = nullptr;
        } else {
            delete root;
        }
    }
}

void BookTree::inorderHelp(BNode *root, bool verbose) const {
    /***********************************
    *      Do not modify
    * ********************************/
    if (root != nullptr) {
        if (verbose) {
            cout << "(";
            inorderHelp(root->_left, verbose);
            cout << root->_key << ":" << root->_author;
            root->_tree.dump();
            inorderHelp(root->_right, verbose);
            cout << ")";
        } else {
            inorderHelp(root->_left, verbose);
            cout << root->_key;
            inorderHelp(root->_right, verbose);
        }
    }
}

void BookTree::dump(bool verbose) const {
    /***********************************
    *      Do not modify
    * ********************************/
    inorderHelp(_root, verbose);
}

int BookTree::findFrequency(string title, string word) {

    if (_root == nullptr) {
        return 0;
    }

    if (_root->_key == title) {

        return _root->findFrequency(word);
    } else {

        BNode *curNode = _root;

        while (title != curNode->_key && curNode != nullptr) {
            //left

            if (title.compare(curNode->_key) < 0) {
                curNode = curNode->_left;

            }
            //right
            if (title.compare(curNode->_key) > 0) {
                curNode = curNode->_right;

            }
        }

        //Makes the searched book the root and returns the word frequency
        if (curNode != nullptr) {

            _root = makeSplay(curNode, curNode->_key);
            return _root->findFrequency(word);
        }

    }
    return 0;

}

void BookTree::dumpTitle(string title) {

    if (_root != nullptr) {


        if (_root->_key == title) {
            _root->_tree.dump();
        } else {
            BNode *curNode = _root;

            while (title != curNode->_key && curNode != nullptr) {
                //left
                if (title.compare(curNode->_key) < 0) {
                    curNode = curNode->_left;
                }
                //right
                if (title.compare(curNode->_key) > 0) {
                    curNode = curNode->_right;
                }
            }
            //Makes the searched book the root and returns the word frequency
            if (curNode != nullptr) {
                _root->_tree.dump();
            }

        }
    }
}

int BookTree::searchCount(string title, string word) {

    if (_root == nullptr) {
        return 0;
    }
    if (_root->_key == title) {
        return _root->searchCount(word);
    } else {
        BNode *curNode = _root;

        while (title != curNode->_key && curNode != nullptr) {
            //left
            if (title.compare(curNode->_key) < 0) {
                curNode = curNode->_left;
            }
            //right
            if (title.compare(curNode->_key) > 0) {
                curNode = curNode->_right;
            }
        }
        //Makes the searched book the root and returns the word frequency
        if (curNode != nullptr) {
            _root = makeSplay(curNode, curNode->_key);
            return _root->searchCount(word);
        }

    }
    return 0;
}

int BookTree::getTextTreeHeight(string title) {

    if (_root == nullptr) {
        return 0;
    }
    if (_root->_key == title) {
        return _root->getTextTreeHeight();
    } else {
        BNode *curNode = _root;

        while (title != curNode->_key && curNode != nullptr) {
            //left
            if (title.compare(curNode->_key) < 0) {

                curNode = curNode->_left;
            }
            //right
            if (title.compare(curNode->_key) > 0) {

                curNode = curNode->_right;
            }
        }
        //Makes the searched book the root and returns the word frequency
        if (curNode != nullptr) {
            _root = makeSplay(curNode, curNode->_key);
            return _root->getTextTreeHeight();
        }

    }
    return -1;
}

int BookTree::getWordHeight(string title, string word) {

    if (_root == nullptr) {
        return 0;
    }
    if (_root->_key == title) {
        return _root->getNodeHeight(word);
    } else {
        BNode *curNode = _root;

        while (title != curNode->_key && curNode != nullptr) {
            //left
            if (title.compare(curNode->_key) < 0) {

                curNode = curNode->_left;
            }
            //right
            if (title.compare(curNode->_key) > 0) {

                curNode = curNode->_right;
            }
        }
        //Makes the searched book the root and returns the word frequency
        if (curNode != nullptr) {
            _root = makeSplay(curNode, curNode->_key);
            return _root->getNodeHeight(word);
        }

    }
    return -1;
}

string BookTree::getRootKey() {
    /***********************************
    *      Do not modify
    * ********************************/
    return _root->_key;
}

void BookTree::loadData(string dataFile) {
    /***********************************
    *      This function is implemented
    *      to help you. You should't need
    *      to modify it.
    * ********************************/
    //read the entire file at once
    std::ifstream t(dataFile);
    std::stringstream buffer;
    buffer << t.rdbuf();

    //time to parse the information
    string titleDelimiter = "<==>";
    string itemsDeleimiter = "<=>";
    string s = buffer.str();
    size_t pos = 0;
    string token;
    while ((pos = s.find(titleDelimiter)) != string::npos) {
        token = s.substr(0, pos);//token is complete data for one title
        //get the title
        int tempPos = token.find(itemsDeleimiter);
        string title = token.substr(0, tempPos);
        //convert title to lower case
        std::transform(title.begin(), title.end(), title.begin(), ::tolower);
        token.erase(0, tempPos + itemsDeleimiter.length() + 1);
        //get the author
        tempPos = token.find(itemsDeleimiter);
        string author = token.substr(0, tempPos);
        //convert author to lower case
        std::transform(author.begin(), author.end(), author.begin(), ::tolower);
        token.erase(0, tempPos + itemsDeleimiter.length() + 1);
        //get the text
        string text = token.substr(0, token.length() - 1);//remove last newline
        //clean up the text, remove all non-alphanumeric characters
        for (std::string::iterator iter = text.begin(); iter != text.end();) {
            if (!std::isalnum(*iter) && *iter != ' ')
                iter = text.erase(iter);
            else
                ++iter; // not erased, increment iterator
        }
        //convert text to lower case
        std::transform(text.begin(), text.end(), text.begin(), ::tolower);
        insert(title, author, text);
        //move to info for the next title
        s.erase(0, pos + titleDelimiter.length() + 1);
    }
}