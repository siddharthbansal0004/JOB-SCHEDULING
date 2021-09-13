#include<bits/stdc++.h>
using namespace std;

template<typename T>


class graph
{
    unordered_map<T,vector<T>>adj_list;

public:
	void add_edge(T a,T b)
	{
	// add edge
        adj_list[a].push_back(b);
	}

	void display()
	{
	// Graph
        cout<<endl;
        if( adj_list.empty() )
        {
            cout<<"\nTopology is empty!!!"<<endl;
            return;
        }
        for( auto x: adj_list )
        {
            T node = x.first;
            cout<<node<<"   --->    ";
            for( T y: adj_list[node] )
                cout<<y<<"      ";
            cout<<endl;
            cout<<endl;
        }
	}

   void deadlock()
   {
   	    if( adj_list.empty() )
        {
            cout<<"\nTopology is empty!!!"<<endl;
            return;
        }

        map<T, int> indegree;

        set<T>s;
		for(auto it:adj_list)
		{
			indegree[it.first]=0;
			s.insert(it.first);
		}

		for(auto it:adj_list)
		{
			for(auto nbr:adj_list[it.first])
			{
				indegree[nbr]++;
				s.insert(nbr);
			}
		}
		int n=s.size();

		queue<T>q;
		vector<T> v;

		for(auto it:s)
		{
		    if(indegree[it]==0)
			{
				q.push(it);
			}
		}


		int cnt = 0;
		while (!q.empty())
		{	T node = q.front();
			q.pop();
			v.push_back(node);
			cnt++;
			for (auto nbr : adj_list[node])
			{
				indegree[nbr]--;
				if (indegree[nbr] == 0)
				{
					q.push(nbr);
				}
			}
        }

		if (cnt != n)
        {
            cout<<"\nDeadlock detected!!!"<<endl;
        }
        else
        {
            cout<<"\nNo deadlock detected!"<<endl;
            cout<<"\nProcesses will be executed in the following order: "<<endl;

            for( auto it: v )
                cout<<it<<" --> ";
            cout<<"All jobs executed successfully!!!"<<endl;
        }
   }
};

int main()
{
    graph<int> g;

    while(1)
    {
        system("cls");
        cout<<"\t\t\t         DATA STRUCTURE PROJECT"<<endl;
        cout<<"\t\t\t        ------------------------"<<endl;
        cout<<"\t\t\tDEADLOCK DETECTION IN A PROCESS TOPOLOGY"<<endl;
        cout<<"\t\t\t----------------------------------------"<<endl;

    	cout<<"\n MENU"<<endl;
        cout<<"------"<<endl;

        cout<<"1. Add processes to topology"<<endl;
        cout<<"2. Display processes in the topology"<<endl;
        cout<<"3. Detect the presence of a deadlock in the topology"<<endl;
        cout<<"4. Exit"<<endl;

        cout<<"\nEnter your choice: ";
        int ch;
        cin>>ch;

        if( ch==1 )
        {
            char c='Y';
            while( c=='Y' || c=='y' )
            {
                int p1,p2;
                cout<<"\nEnter the process to be executed first: ";
                cin>>p1;
                /*cin.get();
                getline( cin,p1 );*/

                cout<<"\nEnter the next process to be executed after the process entered above: ";
                cin>>p2;
                /*getline( cin,p2 );*/

                g.add_edge( p1,p2 );
                cout<<"\n\nDo you want to enter more processes? (Y/N) ";
                cin>>c;

                if( c=='n' || c=='N' )
                    break;
            }
        }
        if( ch==2 )
        {
            g.display();
            cin.get();
            cin.get();
        }
        if( ch==3 )
        {
            g.deadlock();
            cin.get();
            cin.get();
        }
        if( ch==4 )
        {
            cout<<"Program ended!!"<<endl;
            break;
        }


    }
    return 0;
}

/*
            Communication Emitter
            Fiber Transmission Channel
            Communication Detector
            Photonic Reservoir
            Training/Testing Algorithm
            Decoded Data-Stream
            Bit-Error-Rate Computation
            Encoded Data-stream
*/





/*
            Initial Configuration
            FEA using graded elements
            Sensitivity Analysis
            Filter(optional)
            Optimization(Optimality Criteria)
            Update Design Variables
            Convergence
            Plot results/post processing
*/
