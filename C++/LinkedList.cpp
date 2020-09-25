#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next = nullptr;
    
    Node(int data){
        this->data = data;
    }
};

class LinkedList{
    public:
        void printNodes();
        void printNodesRecursively(Node *);
        void insertNode(int);
        void deleteNode(int);
        int listSize();
        Node *getHead()
        {return head;}
   
    private:
        Node *head = nullptr;
};

int main()
{
    LinkedList *list = new LinkedList();
    list->insertNode(10);
    list->insertNode(20);
    list->insertNode(30);
    list->insertNode(40);
    list->insertNode(50);
    
    cout <<"List of Nodes (Recursive):\n";
    list->printNodesRecursively(list->getHead());
    
    return 0;
}

/* Returns the size of the linked list */
int LinkedList::listSize(){
    
    Node *curr = head;
    int length = 0;
    
    while(curr){
        length++;
        curr = curr->next;
    }
    
    return length;
}

/* Inserts the node */
void LinkedList::insertNode(int data){
    
    if(!head){ //Executes if the list is empty
        head = new Node(data);
    } else { //Otherwise append the node 
        
        Node *curr = head;
        
        while(curr && curr->next){
            curr = curr->next;
        } 
        
        curr->next = new Node(data);
    }
}

/* Prints all nodes */
void LinkedList::printNodes(){
    
    Node *curr = head;
    
    if(listSize() > 0){
        cout << "List of Nodes: ";
        while(curr){
            cout << curr->data << " ";
            curr = curr->next;
        }
    } else {
        cout <<"There are no nodes in the LinkedList.\n";
    }

}

/* Prints all nodes recursively */
void LinkedList::printNodesRecursively(Node *head){
    
    if(head){
        cout << head->data <<" ";
        printNodesRecursively(head->next);
    } 
}

/* Deletes a node */
void LinkedList::deleteNode(int index){
    
    //There has to be nodes in the list.
    if(listSize() > 0){
        //The index needs to be in range.
        if(index >= 0 and index < listSize()){
            //Current Node
            Node *curr = head;
            //Current Index
            int currentIndex = 0;
            /* Previous Node: Node located before the node that will be deleted
               Next Node: Node located after the node that will be deleted */
            Node *prev = nullptr, *next = nullptr;

            //Traverses through the list
            while(curr){
            
                //Assigns previous node
                if(currentIndex == index - 1 and listSize() > 1){
                   prev = curr; 
                }
                
                //Node that's gonna be deleted
                if(currentIndex == index){
                    
                    //Assigns next node
                    if(curr->next){
                        next = curr->next;
                    }
                    
                    if(listSize() > 1){
                        if(prev and next){ //Middle of the list
                            prev->next = next;
                        } else if(prev and next == nullptr){ //Deleted node was at the last index
                            prev->next = nullptr;
                        } else { //Deleted node was at the first index 
                            head = next;
                        }
                    } else {
                        head = nullptr;
                    }
                    
                    //Deletes the Node
                    delete curr;
                    
                    break;
                }
                currentIndex++;
                curr = curr->next;
            }
        } else {
            cout << "Invalid index number\n";
        }
    } else {
        cout << "There are no nodes in the LinkedList.\n";
    }
}
