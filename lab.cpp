#include <iostream>
using namespace std;

class BT;

class Expression{
    private:
    char Expression [size];
    int length;

    private:
    	friend class BT;
	    Expression(void){
	    length=0;
	}
    void accept(void){
        cout<<"Enter Expression";
        cin>>Exp;
    }
    void display(void){
        cout<<"The Expression is"<<Exp;

    }
};

int main(void){
    Expression E;
    E.accept();
    E.display();
}

struct BTNODE{
    BTNODE*lc;
    char data;
    BTNODE*rc;
};

class BT{
    private:
    BTNODE*root;

    public:
    STACK S;
    void Exptree(Expression&E);
    BT{
        root=NULL;
    }
    void traverse(void){
        preorder(root);
        inorder(root);
        postorder(root);
    }
    
};

void BT::Exptree(Expression&E){
    BTNODE*newnp;
    STACK S;
    for(int i=0;i<E.length;i++){
        newnp=new BTNODE;
        newnp ->data=E.exp[i]
        newnp->lc=newnnp->rc=NULL;
        if(isalpha(E.Exp[i])){
            s.push(newnp);
        }
        else{
            newnp->rc=S.pop();
            newnp->lc=S.pop();
            S.push(newnp);
        }
    }
    root=S.pop();
}
