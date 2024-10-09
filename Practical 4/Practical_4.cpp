//Question
/*
Construct an Expression Tree from postfix and prefix expression. Perform recursive and nonrecursive In-order, pre-order and post-order traversals.
*/

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

// Struct for Binary Tree Node
struct BTNODE {
    string data;              
    BTNODE* lc;             
    BTNODE* rc;  

    BTNODE(string val) : data(val), lc(nullptr), rc(nullptr) {}
};

class Expression;

class BT {
public:
    void display(BTNODE* root);
    void preOrderRecursive(BTNODE* root);
    void inOrderRecursive(BTNODE* root);
    void postOrderRecursive(BTNODE* root);
    void preOrderNonRecursive(BTNODE* root);
    void inOrderNonRecursive(BTNODE* root);
    void postOrderNonRecursive(BTNODE* root);
};

class Expression {
private:
    BTNODE* root;

public:
    Expression() : root(nullptr) {}

    void buildPostfix(const string& postfix) {
        stack<BTNODE*> stk;
        istringstream iss(postfix);
        string token;

        while (iss >> token) {
            if (isalnum(token[0])) {  
                stk.push(new BTNODE(token));
            } else {  
                BTNODE* node = new BTNODE(token);
                node->rc = stk.top(); stk.pop();
                node->lc = stk.top(); stk.pop();
                stk.push(node);
            }
        }
        root = stk.top(); stk.pop();
    }

    void buildPrefix(const string& prefix) {
        stack<BTNODE*> stk;
        for (int i = prefix.length() - 1; i >= 0; i--) {
            string token(1, prefix[i]);
            if (isalnum(prefix[i])) {
                stk.push(new BTNODE(token));
            } else {  
                BTNODE* node = new BTNODE(token);
                node->lc = stk.top(); stk.pop();
                node->rc = stk.top(); stk.pop();
                stk.push(node);
            }
        }
        root = stk.top(); stk.pop();
    }

    friend class BT;

    void display() {
        BT bt;
        bt.display(root);
    }

    void preOrderRecursive() {
        BT bt;
        bt.preOrderRecursive(root);
    }

    void inOrderRecursive() {
        BT bt;
        bt.inOrderRecursive(root);
    }

    void postOrderRecursive() {
        BT bt;
        bt.postOrderRecursive(root);
    }

    void preOrderNonRecursive() {
        BT bt;
        bt.preOrderNonRecursive(root);
    }

    void inOrderNonRecursive() {
        BT bt;
        bt.inOrderNonRecursive(root);
    }

    void postOrderNonRecursive() {
        BT bt;
        bt.postOrderNonRecursive(root);
    }
};


void BT::display(BTNODE* root) {
    if (root) {
        display(root->lc);
        cout << root->data << " ";
        display(root->rc);
    }
}

void BT::preOrderRecursive(BTNODE* root) {
    if (root) {
        cout << root->data << " ";
        preOrderRecursive(root->lc);
        preOrderRecursive(root->rc);
    }
}


void BT::inOrderRecursive(BTNODE* root) {
    if (root) {
        inOrderRecursive(root->lc);
        cout << root->data << " ";
        inOrderRecursive(root->rc);
    }
}


void BT::postOrderRecursive(BTNODE* root) {
    if (root) {
        postOrderRecursive(root->lc);
        postOrderRecursive(root->rc);
        cout << root->data << " ";
    }
}


void BT::preOrderNonRecursive(BTNODE* root) {
    if (!root) return;
    stack<BTNODE*> stk;
    stk.push(root);
    while (!stk.empty()) {
        BTNODE* node = stk.top(); stk.pop();
        cout << node->data << " ";
        if (node->rc) stk.push(node->rc);
        if (node->lc) stk.push(node->lc);
    }
}

void BT::inOrderNonRecursive(BTNODE* root) {
    stack<BTNODE*> stk;
    BTNODE* curr = root;
    while (curr || !stk.empty()) {
        while (curr) {
            stk.push(curr);
            curr = curr->lc;
        }
        curr = stk.top(); stk.pop();
        cout << curr->data << " ";
        curr = curr->rc;
    }
}


void BT::postOrderNonRecursive(BTNODE* root) {
    if (!root) return;
    stack<BTNODE*> stk;
    BTNODE* lastVisited = nullptr;
    while (!stk.empty() || root) {
        while (root) {
            stk.push(root);
            root = root->lc;
        }
        BTNODE* peekNode = stk.top();
        if (peekNode->rc && lastVisited != peekNode->rc) {
            root = peekNode->rc;
        } else {
            cout << peekNode->data << " ";
            lastVisited = peekNode;
            stk.pop();  
        }
    }
}

int main() {
    Expression expr;
    string postfix, prefix;

    cout << "Enter postfix expression (space-separated): ";
    getline(cin, postfix);
    expr.buildPostfix(postfix);
    cout << "Postfix Expression Tree (in-order): ";
    expr.display();
    cout << "\nPre-order (Recursive): ";
    expr.preOrderRecursive();
    cout << "\nIn-order (Recursive): ";
    expr.inOrderRecursive();
    cout << "\nPost-order (Recursive): ";
    expr.postOrderRecursive();
    cout << "\nPre-order (Non-Recursive): ";
    expr.preOrderNonRecursive();
    cout << "\nIn-order (Non-Recursive): ";
    expr.inOrderNonRecursive();
    cout << "\nPost-order (Non-Recursive): ";
    expr.postOrderNonRecursive();

    cout << endl;

    cout << "\nEnter prefix expression (space-separated): ";
    getline(cin, prefix);
    expr.buildPrefix(prefix);
    cout << "Prefix Expression Tree (in-order): ";
    expr.display();
    cout << "\nPre-order (Recursive): ";
    expr.preOrderRecursive();
    cout << "\nIn-order (Recursive): ";
    expr.inOrderRecursive();
    cout << "\nPost-order (Recursive): ";
    expr.postOrderRecursive();
    cout << "\nPre-order (Non-Recursive): ";
    expr.preOrderNonRecursive();
    cout << "\nIn-order (Non-Recursive): ";
    expr.inOrderNonRecursive();
    cout << "\nPost-order (Non-Recursive): ";
    expr.postOrderNonRecursive();

    cout << endl;
    return 0;
}

//Output:
/*

*/
