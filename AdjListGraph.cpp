#include <iostream>
#include <queue>    // queue ke liye
using namespace std;
struct Edge;
struct Vertex{
	char data;
	Vertex* next;
	Edge* edgeList;	//edge ki list la start point
	bool visited;
};

struct Edge{
	Vertex* v;		//jis edge se connect hy(destination)
	Edge* next;
};
Vertex* head=NULL;

//Add Vertex
void addVertex(char data){
	Vertex* newVertex=new Vertex;
	newVertex->data=data;
	newVertex->next=NULL;
	newVertex->edgeList=NULL;
	if(head==NULL){
		head=newVertex;
		return;
	}
	Vertex* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newVertex;
}
//Remove Vertex
void removeVertex(char searchFor){
    Vertex* temp=head;
    Vertex* vPrev=NULL;
    Vertex* del=NULL;
    
    while(temp!=NULL){
        if(temp->data==searchFor){
            del=temp;
            break;
        }
        vPrev=temp;
        temp=temp->next;
    }
    if(del==NULL) return;
    
    // Del ki apni edges delete karo
    Edge* eTemp=del->edgeList;
    while(eTemp!=NULL){
        Edge* e=eTemp;
        eTemp=eTemp->next;
        delete e;
    }
    del->edgeList=NULL;
    
    // Har vertex ki edgeList se del ka reference remove karo
    Vertex* v=head;
while(v!=NULL){
    Edge* curr=v->edgeList;
    Edge* ePrev=NULL;
    while(curr!=NULL){
        if(curr->v==del){
            if(ePrev==NULL){
                v->edgeList=curr->next;
                delete curr;
                curr=v->edgeList;
            } else {
                ePrev->next=curr->next;
                delete curr;
                curr=ePrev->next;
            }
        } else {
            ePrev=curr;
            curr=curr->next;
        }
    }
    v=v->next;
}
if(vPrev==NULL){
    head=del->next;
} else {
    vPrev->next=del->next;
}
delete del;
}
//Add Edge
void addEdge(char src,char dest){
	Vertex* s=NULL;
	Vertex* d=NULL;
	Vertex* temp=head;
	while(temp!=NULL){
		if(temp->data==src){
			s=temp;
		}
		if(temp->data==dest){
			d=temp;
		}
		temp=temp->next;
	}
		if(s==NULL || d==NULL){
			cout << "Vertex does not exist.";
			return;
		}
		
		]'
		']'
		eTemp->next=newEdge;
	}
	void RemoveEdge(char src,char dest){
		Vertex* temp=head;
		while(temp!=NULL){
		if(temp->data!=src){
			temp=temp->next;
			continue;
		}
		Edge* curr = temp->edgeList; // Vertex ki edge list
		Edge* prev = NULL;
		while(curr!=NULL){
			if(curr->v->data==dest){
			if(prev==NULL){
				temp->edgeList=curr->next;
			}
			else{
				prev->next = curr->next;
    			delete curr;
				return;
			}
			prev=curr;
			curr=curr->next;
		}
	}
}
}
	
//find degree
int findDegree(char vertex){
	Vertex* temp=head;
	while(temp!=NULL){
		if(temp->data==vertex){
			Edge* eTemp=temp->edgeList;
			int count=0;
			while(eTemp!=NULL){
				count++;
			eTemp=eTemp->next;
		}
		return count;
	}
	temp=temp->next;
}
cout << "Vertex not found.\n";
    return -1;
}
//find indegree 
//Indegree mein hume poora graph dekhna padta tha ki k?? 
//humari taraf point kar raha hai — lekin outdegree mein sirf apni khud ki list kaafi ha
int findInDegree(char vertex){
	int indegree=0;
	Vertex* temp=head;
	while(temp!=NULL){
		Edge* eTemp=temp->edgeList;
		while(eTemp!=NULL){
			if(eTemp->v->data==vertex){
			indegree++;
		}
		eTemp=eTemp->next;
	}
		temp=temp->next;
	}
	return indegree;
}

//find outdegree

//Hum pehle poori vertex list mein se apni target vertex dhundtay hain. 
//Jab mil jaaye, to sirf us ki edge list traverse karte hain aur 
//har edge pe counter badhate hain — 
//kyunki har edge matlab ek bahar jaane wala connection hai"


int findOutDegree(char vertex){
	int outDegree=0;
	Vertex* temp=head;
	while(temp!=NULL){
		if(temp->data==vertex){
		Edge* eTemp=temp->edgeList;
		
			while(eTemp!=NULL){
				outDegree++;
				eTemp=eTemp->next;
			}
			temp=temp->next;
		}
	return outDegree;
}
//==================================================
//Queue for BFS
//==================================================

struct QNode{
	Vertex* v;
	QNode* next;
};
QNode* front=NULL;
QNode* rear=NULL;
void EnQueue(Vertex* v){
	QNode* newNode=new QNode;
	newNode->v=v;
	newNode->next=NULL;
	//Empty queue -> front = rear = NULL
	//One element -> front = rear
	//More elements -> front first pe, rear last pe
	if(rear==NULL){
		rear=front=newNode;
	}
	rear->next = newNode;
	rear=newNode;
}
Vertex* DeQueue(){
	if(front==NULL){
		cout << "Queue Empty";
	}
	QNode* temp=front;
	front=front->next;
	cout << temp->v->data <<"DeQueued" << endl;		
	delete temp;
	
	if (front == NULL) {
        rear = NULL;
    }
}
//BFS
void bFS(char startVertex){
	//Pehle saare vertices ki visited = false karo
	Vertex* temp=head;
	Vertex* start=NULL;
	while(temp!=NULL){
		temp->visited=false;
		temp=temp->next;
	}
	temp=head;
	while(temp!=NULL){
		if(temp->data==startVertex){
		start=temp;
		break;
	}
		temp=temp->next;
	}
	if (start == NULL)
    {
        cout << "Start vertex not found\n";
        return;
    }
	EnQueue(start);
    start->visited=true;		//start=1st
    //  BFS loop
    while (!isEmpty()) {
        Vertex* curr = deQueue();		 
        cout << curr->data << " ";  	// print karo

        // Neighbours dekho (edgeList se!)
        Edge* eTemp = curr->edgeList;
        while (eTemp != NULL) {
            if (!eTemp->v->visited) {		//check if visited
                eTemp->v->visited = true;		//if not, then update visited
                EnQueue(eTemp->v);
            }
            eTemp = eTemp->next;		//jb ye end hoga tw wapas bfs loop start hojyega until q is empty
        }
        
        
void printPath(Vertex* end) {
    if (end == NULL) return;
    printPath(end->parent);  // pehle upar jao
    cout << end->data << " ";  // phir print karo
}
void BFS_findPath(int src, int dest){
    //reset visited
    Vertex* temp = head;
    while(temp != NULL){
        temp->visited = false;
        temp->parent = NULL;
        temp = temp->next;
    }

    // find start & destination
    Vertex* start = NULL;
    Vertex* dest = NULL;

    temp = head;
    while(temp != NULL){
        if(temp->data == startVertex) start = temp;
        if(temp->data == destVertex) dest = temp;
        temp = temp->next;
    }

    if(start == NULL || dest == NULL){
        cout << "Vertex not found!\n";
        return;
    }
	// BFS shuru karo
	start->visited = true;
	EnQueue(start);
	
    // 4. BFS
    while(front!=NULL){		//Queue ka front
        Vertex* curr = DeQueue();

        if (curr->data == dest) {
    			printPath(curr);   // sirf destination milne pe path print karo
   				return;
}

        EdgeNode* eTemp = curr->edgeList;
        while (eTemp != NULL) {
            if (!eTemp->v->visited) {
                eTemp->v->visited = true;
                eTemp->v->parent = curr;
                EnQueue(eTemp->v);
            }
            eTemp = eTemp->next;
        } 
    }

    cout << "Path exist nahi karta!" << endl;
}
//============================================
// STACK FOR DFS
//============================================
struct SNode{
    Vertex* v;
    SNode* next;
};

SNode* top = NULL;

// Push
void push(Vertex* v){
    SNode* newNode = new SNode;
    newNode->v = v;
    newNode->next = top;
    top = newNode;
}

// Pop
Vertex* pop(){
    if(top == NULL){
        return NULL;
    }
    SNode* temp = top;
    Vertex* v = temp->v;
    top = top->next;
    delete temp;
    return v;
}

// Check empty
bool isEmptyStack(){
    return top == NULL;
}
//===========================
//DFS
//===========================
void DFS(char startVertex){
	//  reset visited
    Vertex* temp = head;
    while(temp != NULL){
        temp->visited = false;
        temp = temp->next;
    }
    // 2. start vertex dhundo
    Vertex* start = NULL;
    temp = head;
    while(temp != NULL){
        if(temp->data == startVertex){
            start = temp;
            break;
        }
        temp = temp->next;
    }

    if(start == NULL){
        cout << "Start vertex not found\n";
        return;
    }
	// stack me push
	start->visited=true;
	push(start);
	// DFS loop
    while(!isEmptyStack()){
        Vertex* curr = pop();
	     cout<< curr->data;
		    // neighbors push karo
            Edge* eTemp = curr->edgeList;
            while(eTemp != NULL){
                if(!eTemp->v->visited){
                	eTemp->v->visited=true;
                    push(eTemp->v);
                }
                eTemp = eTemp->next;
            }
        }
    }
//================================
//Cycle using DFS
//================================
void DFS(char startVertex){
    // 1. Reset visited
    Vertex* temp = head;
    while(temp != NULL){
        temp->visited = false;
        temp = temp->next;
    }

    // 2. Start vertex dhundo
    Vertex* start = NULL;
    temp = head;
    while(temp != NULL){
        if(temp->data == startVertex){
            start = temp;
            break;
        }
        temp = temp->next;
    }
    if(start == NULL){
        cout << "Start vertex not found\n";
        return;
    }
	//agar visited+non parent=yes cycle .
    // Stack me parent bhi saath push karenge
    // Isliye ek parallel parent stack banate hain
    Vertex* parentStack[100];  // parent track karne ke liye
    int parentTop = -1;

    bool hasCycle = false;

    start->visited = true;
    push(start);
    parentTop++;
    parentStack[parentTop] = NULL;  // start ka koi parent nahi

    while(!isEmptyStack()){
        Vertex* curr = pop();
        Vertex* parent = parentStack[parentTop]; 
        parentTop--;
        cout << curr->data << " ";

        Edge* eTemp = curr->edgeList;
        while(eTemp != NULL){
            if(!eTemp->v->visited){
                eTemp->v->visited = true;
                push(eTemp->v);
                parentTop++;
                parentStack[parentTop]=curr;
            }
            else if(eTemp->v != parent){
                // Visited bhi hai, aur parent bhi nahi — CYCLE!
                hasCycle = true;
            }
            eTemp = eTemp->next;
        }
    }

    if(hasCycle)
        cout << "\nCycle HAI graph mein!\n";
    else
        cout << "\nCycle NAHI hai graph mein.\n";
}

//=============================================================
//IS CONNECTED OR NOT?
//=============================================================

// Total vertices count karne ka helper
int countVertices(){
    int count = 0;
    Vertex* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

bool isConnected(){
    if(head == NULL) 
	return true;  // empty graph

    // Saare visited = false karo
    Vertex* temp = head;
    while(temp != NULL){
        temp->visited = false;
        temp = temp->next;
    }

    // Pehle vertex se DFS chalao (stack use karke)
    push(head);
    head->visited = true;
    int visitedCount = 0;

    while(!isEmptyStack()){
        Vertex* curr = pop();
        visitedCount++;

        Edge* eTemp = curr->edgeList;
        while(eTemp != NULL){
            if(!eTemp->v->visited){
                eTemp->v->visited = true;
                push(eTemp->v);
            }
            eTemp = eTemp->next;
        }
    }

    // Step 3: Compare karo
    int total = countVertices();

    if(visitedCount == total){
        cout << "Graph  is CONNECTED!\n";
        return true;
    } else {
        cout << "Graph NOT connected — "
             << (total - visitedCount) 
             << " vertices isolated hain!\n";
        return false;
    }
}
//=====================================
//IS ADJACENT?


//Kaam kaise karta hai:
//
//Pehle src vertex dhundho
//Uski edgeList traverse karo
//Agar kisi edge ka destination dest se match kare ? adjacent hain
//Agar poori list khatam ho jaaye aur na mile ? adjacent nahi

//EdgeList mein sirf direct neighbors hote hain, isliye traverse karo ya na karo — 
//indirect kabhi milega hi nahi! 

//======================================
void is_adjacent(char src, char dest){
	Vertex* temp=head;
	while(temp!=NULL){
		if(temp->data==src){
		Edge* eTemp=temp->edgeList;
		while(eTemp!=NULL){
			if(eTemp->v->data=dest){
				cout<< "Source and destination is adjacent";
			}
			
			eTemp=eTemp->next;
		}
		cout<< "Source and destination are not ajacent";
		temp=temp->next;
	}
	cout << "Vertex not found!\n";
	}
}

//============================================
//FIND NEIGHBOURS
//Logic simple hai:

//Pehle target vertex dhundo (vertex list traverse karo)
//Jab mil jaye, uski edgeList traverse karo
//Har edge ka v->data print karo — yahi uske neighbours hain

//===============================================
void FindNeighbour(char vertex){
	Vertex* temp=head;
	if(head!=NULL){
		if(head->data=vertex){
			Edge* eTemp=temp->edgeList;
			cout<< "List of neighbours."
			if(eTemp!=NULL){
				cout<< eTemp->v->data;
			}
			eTemp=eTemp->next;
		}
		temp=temp->next;
	}
	cout<< "Vertex not Found.";
}
//=====================================
//SEARCH FUNCTION
//=====================================
bool searchVertex(char vertex){
    Vertex* temp = head;
    
    while(temp != NULL){
        if(temp->data == vertex){
            cout << "Vertex '" << vertex << "' found!\n";
            return true;
        }
        temp = temp->next;
    }
    
    cout << "Vertex '" << vertex << "' not found!\n";
    return false;
}
//Display
void display(){
    Vertex* temp = head;
    while(temp != NULL){
        cout << temp->data << "-> ";
        Edge* eTemp = temp->edgeList;
        while(eTemp != NULL){
            cout << eTemp->v->data << " ";
            eTemp = eTemp->next;
        }
        cout << endl;
        temp = temp->next;
    }
}
int main(){
	addVertex('A');
	addVertex('B');
	addVertex('C');
	addEdge('A','B');
	addEdge('A','C');
	display();
}
