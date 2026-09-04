#include<iostream>
#include<string>
using namespace std;

struct Node
{
	string team;
	Node* next;
	
};

class CircularLinkedList
{
	private:
		Node* last;
		
	public:
		CircularLinkedList()
		{
			last = NULL;
		}
		
		void addTeam(string name)
		{
			Node* newNode = newNode;
			newNode->team = name;
			
			if (last==NULL)
			{
				last = newNode;
				newNode->next = newNode;
			}
			else
			{
			  newNode->next = last->next;
			  last->next = newNode;
			  last = newNode;	
			}
		}
		
		void displayTeam()
		{
			if(last == NULL){
				cout<<"No teams avaliable.\n";
				return;
			}
			
			Node*temp = last->next;
			
			cout<<"\nTeam in tournament:\n";
			
			do{
				cout<<temp->team<<"->";
				temp = temp->next;
			}while(temp != last->next);
			
			cout<<"(back to first team)\n";
		}
		
		void roundRobin(int rounds){
			if (last == NULL){
				cout<<"No team avaliable.\n";
				return;
			}
			
			Node* start = last->next;
			
			cout<<"\n---- Round Robin Schedule----\n";
			
			for (int r=1; r<=rounds;r++)
			{
				cout<<"\nRound "<< r <<":\n";
				
				Node* current = start;
				
				do{
					Node* opponent = current->next;
					
					if(opponent != start){
						cout<<current->team<<"vs"
						    <<opponent->team<<endl;
					}
					
					current = current->next;
				}while(current !=start);
				
				start = start->next;
			}
		}
};

int main()
{
	CircularLinkedList tournament;
	int n;
	string teamName;
	
	cout<<"Enter Number of team: ";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cout<<"Enter team"<<i+1<<"name: ";
		cin>>teamName;
		tournament.addTeam(teamName);
	}
	 
	tournament.displayTeam();
	
	tournament.roundRobin(n-1);
	
	return 0;
}

