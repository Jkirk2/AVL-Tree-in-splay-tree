#include "wordTree.h"

WordTree::~WordTree() {

    //deletes all but the root
    if(_root != nullptr) {
        clearTree(_root);
    }
    //delete the root which is nullptr
    delete _root;
}

void WordTree::updateHeight(Node *aNode) {

    //heights of the sub nodes
    int leftHeight = 0;
    int rightHeight = 0;

    //finds the heights of the subtrees
    if (aNode->_left == nullptr) {
        leftHeight = -1;
    } else {
        leftHeight = aNode->_left->_height;
    }
    if (aNode->_right == nullptr) {
        rightHeight = -1;
    } else {
        rightHeight = aNode->_right->_height;
    }


    //sets the new height to the greater of the two heights + 1
    if (leftHeight >= rightHeight) {
        aNode->_height = leftHeight + 1;
    } else {
        aNode->_height = rightHeight + 1;
    }
}

void WordTree::clearTree(Node *aNode) {

    //goes down left until its null
    if (aNode->_left != nullptr) {
        clearTree(aNode->_left);
    }
    //goes down right until its nul
    if (aNode->_right != nullptr) {
        clearTree(aNode->_right);
    }

    //deletes since all subtrees below it have been deleted
    if (aNode == _root) {
        aNode = nullptr;
    } else {
        delete aNode;
    }
}

void WordTree::inOrder(Node *aNode, std::ostream &ostr) {
    /***********************************
     *      Do not modify
     * ********************************/
    if (aNode != nullptr) {
        ostr << "[";
        inOrder(aNode->_left, ostr);
        ostr << aNode->_value << ":" << aNode->_count << ":" << aNode->_height;
        inOrder(aNode->_right, ostr);
        ostr << "]";
    }
}

Node *WordTree::find(Node *aNode, const string &element) {
    // if its blank return nullptr
    if (aNode == nullptr) {
        return nullptr;
    }
        //if its before the node alphebetically
    else if (element.compare(aNode->_value) < 0) {
        return find(aNode->_left, element);
    }
        //if its after the node alphebetically
    else if (element.compare(aNode->_value) > 0) {
        return find(aNode->_right, element);
    } else {
        return aNode;
    }

}

Node *WordTree::find(const string &element) {

    return find(_root, element);
}

Node *WordTree::leftRotation(Node *aNode) {
    if (aNode->_right == nullptr) {
        throw out_of_range("Error: Left rotation left node (new root) is non existent (null)");
    }

    //stores the new root
    Node *rightChild = aNode->_right;



    //makes the right child of the old root the new roots left child
    aNode->_right = rightChild->_left;
    //updates the parents
    rightChild->_parent = aNode->_parent;
    aNode->_parent = rightChild;
    //Makes the new roots right child the old root finishing the rotation
    rightChild->_left = aNode;
    updateHeight(aNode);
    updateHeight(rightChild);
    //updates the root
    if (_root == aNode) {
        _root = rightChild;
    }
    return rightChild;
    return nullptr;
}

Node *WordTree::rightRotation(Node *aNode) {
    if (aNode->_left == nullptr) {
        throw out_of_range("Error: Right rotation left node (new root) is non existent (null)");
    }

    //stores the new root
    Node *leftChild = aNode->_left;



    aNode->_left = leftChild->_right;


    //updates the parents
    leftChild->_parent = aNode->_parent;
    aNode->_parent = leftChild;
    //Makes the new roots right child the old root finishing the rotation
    leftChild->_right = aNode;
    updateHeight(aNode);
    updateHeight(leftChild);
    //updates the root
    if (_root == aNode) {
        _root = leftChild;
    }
    return leftChild;
}

int WordTree::checkBalance(Node *aNode) {

    int leftHeight = 0;
    int rightHeight = 0;
    if (aNode == nullptr) {
        return 0;
    }
    //the left childs height +1 checks for null
    if (aNode->_left == nullptr) {
        leftHeight = 0;
    } else {
        leftHeight = aNode->_left->_height + 1;
    }

    //the right childs height +1 checks for null
    if (aNode->_right == nullptr) {
        rightHeight = 0;
    } else {
        rightHeight = aNode->_right->_height + 1;
    }

    //returns the left child height minus the right child height
    return leftHeight - rightHeight;
}

Node *WordTree::reBalance(Node *aNode) {
    //left heavy
    if (checkBalance(aNode) > 1) {
        //checks if the child is right heavy for double rotation
        if (checkBalance(aNode->_left) <= -1) {
            //does left rotation on the child node
            aNode->_left = leftRotation(aNode->_left);
        }
        //does a right rotation
        return rightRotation(aNode);

    } else if (checkBalance(aNode) < -1) { // right heavy

        //checks to see if the node is left heavy for double rotation
        if (checkBalance(aNode->_right) >= 1) {
            //does a right rotation on the child node
            aNode->_right = rightRotation(aNode->_right);
        }
        //does a left rotation
        return leftRotation(aNode);
    }
    //if there are no unbalances
    return aNode;
}

void WordTree::insert(const string &element) {


    //checks to see if the tree is empty
    if (_root == nullptr) {
        Node *newNode = new Node(element);
        _root = newNode;
        _root->_count++;
        updateHeight(_root);
    } // checks if root is the same word as the element
    else if (element.compare(_root->_value) == 0) {
        _root->_count++;
    } else {
        //starts the recursive insert if root is populated and different
        insert(element, _root);
    }

}

Node *WordTree::insert(const string &element, Node *&aNode) {
    //if it is left of the parent
    if (element.compare(aNode->_value) < 0) {
        if (aNode->_left == nullptr) {
            Node *newNode = new Node(element);
            aNode->_left = newNode;
            newNode->_parent = aNode;
            aNode = reBalance(aNode);
        }
        //calls the same function on left child
        insert(element, aNode->_left);

    } else if (element.compare(aNode->_value) > 0) { // if it is right of the parent
        if (aNode->_right == nullptr) {
            Node *newNode = new Node(element);
            aNode->_right = newNode;
            newNode->_parent = aNode;
            aNode = reBalance(aNode);
        }
        //calls the same function on right child
        insert(element, aNode->_right);
    } else { // if it equals the parent
        aNode->_count++;

    }
    //updates the height and rebalances (rebalance will skip if it is balanced)
    updateHeight(aNode);
    aNode = reBalance(aNode);
    return nullptr;
}

void WordTree::dump(std::ostream &ostr) {
    /***********************************
     *      Do not modify
     * ********************************/
    inOrder(_root, ostr);
}

int WordTree::searchCount(string word) {
    return(searchCountHelp(_root,word, 0) );
}

int WordTree::searchCountHelp(Node *aNode, string word, int counter) {
    if (aNode == nullptr) {
        return -1;
    }
        //if its before the node alphebetically
    else if (word.compare(aNode->_value) < 0) {
        return searchCountHelp(aNode->_left, word,counter+1);
    }
        //if its after the node alphebetically
    else if (word.compare(aNode->_value) > 0) {
        return searchCountHelp(aNode->_right, word,counter+1);
    } else {
        return counter;
    }
    return 0;
}

int WordTree::getRootHeight() {
    if(_root == nullptr ){
        return 0;
    }
    return _root->_height;
}

int WordTree::getNodeHeight(string word) {
    return getNodeHeightHelp(_root, word);
}

int WordTree::getNodeHeightHelp(Node *aNode, string word) {
    if (aNode == nullptr) {
        return -1;
    }
        //if its before the node alphebetically
    else if (word.compare(aNode->_value) < 0) {
        return getNodeHeightHelp(aNode->_left, word);
    }
        //if its after the node alphebetically
    else if (word.compare(aNode->_value) > 0) {
        return getNodeHeightHelp(aNode->_right, word);
    } else {
        return aNode->_height;
    }
}