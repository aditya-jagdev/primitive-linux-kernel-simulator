//---------------------------------------------------------------------------------------------------------------------
//----------------------------------ADITYA JAGDEV----------------------------------------------------------------------
//------------------------------------14BCE0185------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string.h>
using namespace std;
//--------------------------------------------------------------------------------------------------------------------- 
int procount=0,pident=0;
//--------------------------------------------------------------------------------------------------------------------- 
struct process
    {
        int remtime,prio;
        char pname[6];
        struct process *next;
        struct process *prev;
    }*start;
//---------------------------------------------------------------------------------------------------------------------     
class processes
    {
        public:
            void add_process(int value);
            void add_after(int value,int prio);
            void remove_process(int value);
            void search_element(int value);
            void display_processes();
            void reduce();
            int get_pos(int value,int prio);
            processes()
            {
                start = NULL;  
            }
    };
//---------------------------------------------------------------------------------------------------------------------
int main()
	{
	int time=0,choice=0,num=1,exit1=1,bt=0,speed=512,priority=5;
	processes pl;
	pl.add_process(-99);
	do{
		system("cls");
		cout<<"\n\t\t\tPRE-EMPTIVE SCHEDULING    \n\t\t\t    ADITYA JAGDEV \n\t\t\t      14BCE0185 \n\n\tTime : "<<setw(5)<<time;
		cout<<"\tProcessor State\n\n";
		pl.display_processes();
		time++;
		pl.reduce();
		if(kbhit())
			{
			cout<<"\n\n\t\t...PAUSED PROCESSOR...\n\n\t1. Add Process\n\t2. Continue\n\t3. Exit\n\t4. 2x Faster Clock\n\t5. 2x Slower Clock\n\n\tYour Choice : ";
			cin>>choice;
			switch(choice)
				{
					case 1:	{
							do{
								procount++;
								do{
								cout<<"\n\tProcess Burst Time : ";
								cin>>bt;
								}while(bt<=0);
								cout<<"\tProcess Priority (integer value) : ";
								cin>>priority;
								pl.add_after(bt,priority);
								cout<<"\n\t\tInput 1 to add another process : ";
								cin>>exit1;
							}while(exit1==1);
							break;
							}
					case 2:	{
							break;
							}
					case 3:	{
							system("cls");
							cout<<"\n\n\n\t\tH";
							Sleep(2);
							cout<<"a";
							Sleep(2);
							cout<<"v";
							Sleep(2);
							cout<<"e";
							Sleep(2);
							cout<<" ";
							Sleep(2);
							cout<<"a";
							Sleep(2);
							cout<<" ";
							Sleep(2);
							cout<<"n";
							Sleep(2);
							cout<<"i";
							Sleep(2);
							cout<<"c";
							Sleep(2);
							cout<<"e";
							Sleep(2);
							cout<<" ";
							Sleep(2);
							cout<<"d";
							Sleep(2);
							cout<<"a";
							Sleep(2);
							cout<<"y";
							Sleep(2);
							cout<<"!";
							Sleep(2);
							cout<<" ";
							Sleep(2);
							cout<<":";
							Sleep(2);
							cout<<")";
							Sleep(200);
							cout<<"\n\n\n\t\t\t.";
							Sleep(200);
							cout<<"\n\n\n\t\t\t.";
							Sleep(200);
							cout<<"\n\n\n\t\t\t.";
							Sleep(200);
							cout<<"\n\n\n\t\t\t.";
							Sleep(200);
							cout<<"\n\n\n\t\t\t.";
							Sleep(200);
							cout<<"\n\n\n\t\t\t.";
							Sleep(200);
							cout<<"\n\n\n\t\t\t.";
							Sleep(200);
							return 0;
							break;
							}
					case 4:	{
							if(speed>2)
								speed=speed/2;
							break;
							}
					case 5:	{
							if(speed<16000)
								speed=speed*2;
							break;
							}
					default:{
							cout<<"\n\tERROR : INVALID INPUT";
							do{}while(!kbhit());
							break;
							}
				};
			}
		Sleep(speed);
		system("cls");
	}while(1);
	}
//---------------------------------------------------------------------------------------------------------------------
void processes::add_process(int value)
    {
        struct process *s, *temp;
        temp = new(struct process); 
        temp->remtime = value;
        temp->prio = -99;
        temp->next = NULL;
        temp->pname[0] = 'P';
        temp->pname[1] = 48 + pident;
        temp->pname[2] = '\0';
        pident++;
		if (start == NULL)
        {
            temp->prev = NULL;
            start = temp;
        }
        else
        {
            s = start;
            while (s->next != NULL)
                s = s->next;
            s->next = temp;
            temp->prev = s;
        }
    }
//---------------------------------------------------------------------------------------------------------------------    
void processes::add_after(int value,int prio)
    {
    	int position;
		position=get_pos(value,prio);						//fetch location after comparing prio, burst and order of arrival
        if (start == NULL)
        {
            cout<<"\n\tERROR : NO_PROCESS_FOUND (cant add after, no IDLE)"<<endl;
            procount--;
			return;
        }
        struct process *tmp, *q;
        int i;
        q = start;
        for (i = 0;i < position - 1;i++)
        {
            q = q->next;
            if (q == NULL)
            {
                cout<<"\n\tERROR : NO_PROCESS_FOUND (cant add after, next var is empty)"<<endl<<" Position : "<<position<<endl;
                procount--;
				return;
            }
        }
        tmp = new(struct process);
        tmp->remtime = value;
        tmp->prio = prio;
        tmp->pname[0] = 'P';
        if(pident<10)
	        {	
				tmp->pname[1] = 48 + (pident%10);
		        tmp->pname[2] = '\0';
			}
			else
				if(pident<100)
					{
						tmp->pname[1] = 48 + (pident/10);
		            	tmp->pname[2] = 48 + (pident%10);
		            	tmp->pname[3] = '\0';
					}
		pident++;
		if (q->next == NULL)
        {
            q->next = tmp;
            tmp->next = NULL;
            tmp->prev = q;      
        }
        else
        {
            tmp->next = q->next;
            tmp->next->prev = tmp;
            q->next = tmp;
            tmp->prev = q;
        }
        cout<<"\n\tProcess Has Been Added..."<<endl;
    }
//---------------------------------------------------------------------------------------------------------------------
void processes::remove_process(int value)
    {
    	procount--;
        struct process *tmp, *q;
        if (start->remtime == value)					//Delete First
        {
            tmp = start;
            start = start->next;  
            start->prev = NULL;
            cout<<"\n\tProcess Deleted..."<<endl;
            free(tmp);
            return;
        }
        q = start;
        while (q->next->next != NULL)
        {   
            if (q->next->remtime == value)  			//Delete In Between
            {
                tmp = q->next;
                q->next = tmp->next;
                tmp->next->prev = q;
                cout<<"Process Deleted..."<<endl;
                free(tmp);
                return;
            }
            q = q->next;
        }
        if (q->next->remtime == value)    				//Delete Last
        { 	
            tmp = q->next;
            free(tmp);
            q->next = NULL;
            return;
        }
        cout<<"\nERROR : NO_PROCESS_FOUND (Cant remove anything)"<<endl;
    }
//---------------------------------------------------------------------------------------------------------------------    
void processes::display_processes()
    {
        struct process *q;
        int i=0;
        if (start == NULL)
        {
            cout<<"\nERROR : NO_PROCESS_FOUND (Cant display, no IDLE)"<<endl;
            return;
        }
        q = start;
        cout<<"\tBurst : ";
        while (q != NULL)
        {
            cout<<setw(5)<<q->remtime<<" ||| ";
            q = q->next;
        }
        cout<<"END"<<endl;
        q = start;
        cout<<"\tPrio  : ";
        while (q != NULL)
        {
            cout<<setw(5)<<q->prio<<" ||| ";
            q = q->next;
        }
        cout<<"END"<<endl;
        q = start;
        cout<<"\tName  : ";
        while (q != NULL)
        {
            cout<<setw(5)<<q->pname<<" ||| ";
            q = q->next;
        }
        cout<<"END"<<endl;
		q = start;
        cout<<"     Position : ";
        while (q != NULL)
        {
            cout<<setw(5)<<i<<" ||| ";
            i++;
            q = q->next;
        }
        cout<<"END"<<endl;
    }
//---------------------------------------------------------------------------------------------------------------------    
void processes::reduce()
	{
		struct process *temp;
        if (start == NULL)
        {
            cout<<"\n\tERROR : NO_PROCESS_FOUND (Cant reduce, no IDLE)"<<endl;
            return;
        }
        temp = start;
        temp=temp->next;
        if(temp!=NULL)
        	{
			temp->remtime--;
			if(temp->remtime==0)
				remove_process(0);
			}
	}
//---------------------------------------------------------------------------------------------------------------------
int processes::get_pos(int value,int prio)
    {
    	int position=0;
    	struct process *temp;
        if (start == NULL)
        {
            cout<<"\n\tERROR : NO_PROCESS_FOUND (Cant reduce, no IDLE found)"<<endl;
            procount--;
			return position;
        }
        temp = start;
        temp = temp->next;
        if(procount==1)
        	return 1;
        else
		if(temp->prio > prio)
        	{
			while( (temp->next!=NULL) && (temp->prio > prio) )
        		{
        			temp=temp->next;
        			position++;
				}
			if(temp->prio>prio)
				position++;
			if(temp->prio==prio)
				{
					while( (temp->next!=NULL) && (temp->prio==prio) && (temp->remtime<=value) )
						{
							temp=temp->next;
							position++;
						}
				}
        	}
        else
        	if(temp->prio==prio)
        		{
        			while( (temp->next!=NULL) && (temp->prio==prio) && (temp->remtime<=value) )
        				{
        					temp=temp->next;
        					position++;
						}
				}
		position++;
		return position;
    }
//---------------------------------------------------------------------------------------------------------------------
//----------------------------------ADITYA JAGDEV----------------------------------------------------------------------
//------------------------------------14BCE0185------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
