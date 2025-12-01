#pragma once
#include <iostream>
#include <queue>
#include "clsDate.h";
#include <stack>
#include <string>
using namespace std;

class clsQueueLine{

private:	
	 string _Prefix;
	short _TotalTickets=0;
	short _AverageServeTime=0;

	class clsTicket {
	private:
		string _Prefix = "";
		short _Number = 0;
		string _TicketTime = "";
		short _WaitingClients = 0;
		short _AverageServeTime = 0;
		
	public:
		clsTicket(string Prefix, short Number, short WaitingClients,short AverageServeTime) {
			_Prefix = Prefix;
			_Number = Number;
			_TicketTime = clsDate::GetSystemDateTimeString();
			_WaitingClients = WaitingClients;
			_AverageServeTime = AverageServeTime;
			

		}
		string Prefix() {
			return _Prefix;
		}

		short Number() {
			return _Number;
		}

		short WaitingClients() {
			return _WaitingClients;
		}
		short ExpectedServeTime() {
			return _AverageServeTime * _WaitingClients;
		}
		string FullNumber() {
			return _Prefix + to_string(_Number);
		}

		void Print() {
			cout << "\n\t\t\t--------------------------------\n";
			cout << "\n\t\t\t\t     " << FullNumber();
			cout << "\n\n\t\t\t     " << _TicketTime;
			cout << "\n\t\t\t     " << "Waiting Clients = " <<_WaitingClients;
			cout << "\n\t\t\t        " << "Serve Time In";
			cout << "\n\t\t\t         " << ExpectedServeTime() << " Minutes.";
			cout << "\n\t\t\t--------------------------------\n";
		}



	};


	
	
	
public:
	queue <clsTicket> QueueLine;
 
	clsQueueLine(string Prefix, short AverageServeTime) {
		_Prefix = Prefix;
		_AverageServeTime = AverageServeTime;
	}

	void IssueTicket() {
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime);
		QueueLine.push(Ticket);


	}

	short WaitingClients() {
		return QueueLine.size();
	}

	short ServedClients() {
		return _TotalTickets - WaitingClients();
	}

	void PrintInfo() {
		 
		cout << "\n\t\t\t--------------------------\n";;
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t--------------------------\n";
		cout << "\n\t\t\t    Prefix          = " <<_Prefix;
		cout << "\n\t\t\t    Total Tickets   = " <<_TotalTickets ;
		cout << "\n\t\t\t    Served Clients  = " <<ServedClients();
		cout << "\n\t\t\t    Waiting Clients = " <<WaitingClients();
		cout << "\n\t\t\t--------------------------\n";


	}

	void PrintTicketsLineRTL() {
		queue <clsTicket> TempQueueLine = QueueLine;

		if (QueueLine.empty()) {
			cout << "\n\t\tTickets: No Tickets.";
		}
		else
			cout << "\n\t\tTickets: ";

		while (!TempQueueLine.empty()) {

			cout << TempQueueLine.front().FullNumber() << " <--";
			TempQueueLine.pop();

		}
		cout << "\n";

  	}

	void PrintTicketsLineLTR() {
		queue <clsTicket> TempQueueLine = QueueLine;
		stack <clsTicket> TempStackLine;

		if (QueueLine.empty()) {
			cout << "\n\t\tTickets: No Tickets.";
		}
		else
			cout << "\n\t\tTickets: ";

		while (!TempQueueLine.empty()) {
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();

		}
		while (!TempStackLine.empty()) {
			cout << TempStackLine.top().FullNumber() << " -->";
			TempStackLine.pop();
		}
		cout << "\n";

	}

	void PrintAllTickets() {
	
		cout << "\n\n\t\t\t       ---Tickets---";

		if (QueueLine.empty())
			cout << "\n\n\t\t\t    ---No Tickets---\n";

		queue <clsTicket> TempQueueLine = QueueLine;

		while (!TempQueueLine.empty()) {
			TempQueueLine.front().Print();
			TempQueueLine.pop();
		}


		}
		
	string WhoIsNext() {
		if (QueueLine.empty()) {
			return "No Clients Left.";
		}
		else
			return QueueLine.front().FullNumber();

	}

	bool ServeNextClient() {
		if (QueueLine.empty()) {
			return false;
		}

		QueueLine.pop();
		return true;

	}


		




		


	
	

};

