#include<iostream>
#include<string.h>
using namespace std;

static int bookcount=0;
class book{
	public:
		long int bookid;
		string author;
		string name;
		int price;
		short int rackno;
		string status;
		int edition;
		long int date;
		
		void enterbookdetails()
		{
		cout<<"enter bookid\n";
		cin>>bookid;
		cout<<"enter author name\n";
		cin>>author;
		cout<<"enter book name\n";
		cin>>name;
		cout<<"enter price\n";
		cin>>price;
		cout<<"enter rack number\n";
		cin>>rackno;
		cout<<"enter status (issued||not issued)\n";
		cin>>status;
		cout<<"enter year edition\n";
		cin>>edition;
		cout<<"enter current date (date||month||year)\n";
		cin>>date;
		cout<<"book details entered successfully!!\n";
		}
		
		void displaybookdetails()
		{
		cout<<"\n\n\nbook details are as follows:\n\n";
		cout<<"Bookid\n";
		cout<<bookid<<endl;
		cout<<"author name\n";
		cout<<author<<endl;
		cout<<"book name\n";
		cout<<name<<endl;
		cout<<"price\n";
		cout<<price<<endl;
		cout<<"rack number\n";
		cout<<rackno<<endl;
		cout<<"status (issued||not issued)\n";
		cout<<status<<endl;
		cout<<"year edition\n";
		cout<<edition<<endl;
		cout<<"current date (date||month||year)\n";
		cout<<date<<endl;
		}
		
		void updatestatus()
		{
			cout<<"enter new status\n";
			cin>>status;
			cout<<endl;
			cout<<"status updated!\n";
		}
};

class journals:virtual public book{
	public:
	string journal;
	
	journals(){
	cout<<"enter name of journal\n";
	cin>>journal;
	cout<<"\nfeeded!\n";
	}
};

class Studybooks: virtual public book{
	public:
	string study;
	
	Studybooks(){
	cout<<"enter name of study book\n";
	cin>>study;
	cout<<"\nfeeded!\n";
}
};

class magazines:virtual public book{
	public:
	string magazine;
	
	magazines()
	{
	cout<<"enter name of magazine\n";
	cin>>magazine;
	cout<<"\nfeeded!\n";
}
};

class librarian:virtual public book{
	public:
	int libname;
	short int s,c;
	int days,fine=0;
	string searchbook;
	string password;
	
	void searchbooks()
	{
		cout<<"enter the name of the book to search\n";
		cin>>searchbook;
		cout<<"searching.....\n";
	}
	
	void verifymember()
	{
		cout<<"\nenter your name\n";
		cin>>libname;
		cout<<"\nenter password\n";
		cin>>password;
		cout<<"\nmember verified!\n";
		
	}
	
	void issuebook()
	{
		cout<<"do you want you issue a new book? (yes=1||no=0)\n";
		cin>>s;
		if (s==1)
		{
			bookcount++;
		}
	}
	
	void calculatefine()
	{
		cout<<"\nenter the number of days late for submission\n";
		cin>>days;
		cout<<"\nfine is rupees 50 per week\n";
		fine=days/7;
		fine=fine*50;
		cout<<"\nyour totall fine is: "<<fine<<endl;
	}
	
	void createbill()
	{
		cout<<"your total bill is: (fine) \n";
		cout<<fine<<endl;
		cout<<"first fill fine\n";
	}
	
	void returnbook()
	{
		cout<<"do you want to return book? (yes=1||no=0)\n";
		cin>>c;
	}
	
};

class transaction:public librarian{
	public:
	long int transid;
	long int memberid;
	int dateofissue;
	int duedate;
	long int a,b,c,d;
	
	void createtransaction()
	{
		cout<<"enter transaction Id\n";
		cin>>transid;
		cout<<"enter member Id\n";
		cin>>memberid;
		cout<<"enter date of issue (date and month )\n";
		cin>>dateofissue;
		cout<<"enter due date(date and month)\n";
		cin>>duedate;
		
		cout<<"transaction created successfully!!\n";
	}
	
	void display()
	{
		cout<<"the details entered are as follows:\n";
		
		cout<<"transaction Id\n";
		cout<<transid<<endl;
		cout<<"member Id\n";
		cout<<memberid<<endl;
		cout<<"date of issue (date and month )\n";
		cout<<dateofissue<<endl;
		cout<<"due date(date and month)\n";
		cout<<duedate<<endl;	
	}
	void deletetransaction()
	{
		cout<<"initialising transaction deletion\n";
		
		a=transid;
		transid=0;
		cout<<"trans id deleted!\n";
		
		b=memberid;
		memberid=0;
		cout<<"member id deleted!\n";
		
		c=dateofissue;
		dateofissue=0;
		cout<<"date of issue deleted!\n";
		
		d=duedate;
		duedate=0;
		cout<<"duedate deleted!\n";
		cout<<"the transaction is deleted!!";
	}
	
	void retrievetransaction()
	{
		cout<<"retrieving transaction....\n";
		cout<<"the details entered were as follows:\n";
	
		cout<<"transaction Id\n";
		cout<<a;
		cout<<"member Id\n";
		cout<<b;
		cout<<"date of issue (date and month )\n";
		cout<<c;
		cout<<"due date(date and month)\n";
		cout<<d;
		
		cout<<"transaction retrived successfully!";
	}
	
};

class bill:public transaction{
	public:
	int billno;
	int currentdate;
	int amount;
	
	
	void billcreate()
	{
		cout<<"enter bill number\n";
		cin>>billno;
		
		cout<<"enter current date and month\n";
		cin>>currentdate;
		
		cout<<"enter the amount to be paid\n";
		cin>>amount;
		
		cout<<"bill generated:\n";
		cout<<"Bill number\n";
		cout<<billno;
		
		cout<<"Current date and month\n";
		cout<<currentdate;
		
		cout<<"Amount to be paid\n";
		cout<<amount;
	}
	
	void billupdate()
	{
		cout<<"update your billing deatils:\n";
		cout<<"enter new bill number\n";
		cin>>billno;
		
		cout<<"enter new current date and month\n";
		cin>>currentdate;
		
		cout<<"enter the new amount to be paid\n";
		cin>>amount;
		
		cout<<"bill upadated!\n";
		cout<<" new Bill number\n";
		cout<<billno;
		
		cout<<"new Current date and month\n";
		cout<<currentdate;
		
		cout<<"new Amount to be paid\n";
		cout<<amount;
	}
};

class memberrecord:virtual public book, virtual public bill{
	public:
	int type;
	int dateofmembership;
	int maxbooklimit=2;
	string address;
	long int phoneno;
	
	void retrievemember()
	{
		cout<<"member id\n";
		cout<<memberid;
		cout<<"enter type of record\n";
		cin>>type;
		cout<<"enter date of membership\n";
		cin>>dateofmembership;
		cout<<"max book limit is:\n";
		cout<<maxbooklimit;
		cout<<"enter member name\n";
		cout<<name;
		cout<<"enter address(house place and city)\n";
		cin>>address;
		cout<<"enter phone number\n";
		cin>>phoneno;
		cout<<"member retrieved!\n";
	}
	
	void increasebookissued()
	{
		cout<<"Issue a book:\n";
		bookcount++;
		cout<<"number of issued books increased to :"<<bookcount;
	}
	
	void decreasebookissued()
	{
		cout<<"book returned:\n";
		bookcount--;
		cout<<"number of issued books decreased to :"<<bookcount;
	}
	
	void paycheck()
	{
		cout<<"paycheck:\n";
		cout<<fine;
	}

};


class faculty:public memberrecord{
	public:
		faculty()
		{
		cout<<"faculty library access enabled\n";
	}
};

class students:public memberrecord{
	public:
		students()
		{
		cout<<"student library access enabled\n";
	}
};

void adminmenu(){
	int c;
	book b;
	librarian l;
	transaction t;
	memberrecord m;
	bill i;
	
	
	do{
	cout<<"\n1.verify member\n2. create transaction\n3.delete transaction\n4. retrieve transaction\n5.create bill\n6.update bill\n7.retrieve member\n";
   cout<<"8.increase book issued\n9.decrease book issued\n10. pay check\n11.exit\n"<<endl;
   cout<<"\n\n enter your choice (1-10)";
   cin>>c;
   switch(c)
   {
        case 1:
        	l.verifymember();
        break;
        case 2:
        	t.createtransaction();
        break;
        case 3:
        	t.deletetransaction();
        break;
        case 4:
        	t.retrievetransaction();
        break;
        case 5:
        	i.billcreate();
        break;
        case 6:
        	i.billupdate();
        break;
        case 7:
        	m.retrievemember();
        break;
        case 8:
        	m.increasebookissued();
        break;
        case 9:
        	m.decreasebookissued();
        break;
        case 10:
        	m.paycheck();
        break;
        case 11:
        	exit(0);
        break;
        default:
        cout<<"\ninvalid option option";
    }
} while (c != 11);

}

int main()
{
	int s;
	book b;
	librarian l;
	transaction t;
	memberrecord m;
	bill i;

	
	cout<<"Aarushi Kumar\n";
	cout<<"A2305219401\n";
	



	do{
   cout<<"\n1.Admin menu\n2.enter and display book details\n3.update status\n4.search book\n5.issue book\n6.calculate fine\n7.create bill\n8.return book\n9.access study books\n";
   cout<<"10.access magazines\n11.access journals\n12.access faculty\n13.access student\n14.exit\n"<<endl;
   cout<<"enter your choice(1-9)\n";
   cin>>s;
   switch(s)
   {
        case 1:
        	adminmenu();
        break;
        case 2:
        	b.enterbookdetails();
        	b.displaybookdetails();
        break;
        case 3:
        	b.updatestatus();
        break;
        case 4:
        	l.searchbooks();
        break;
        case 5:
        	l.issuebook();
        break;
        case 6:
        	l.calculatefine();
        break;
        case 7:
        	l.createbill();
        break;
        case 8:
        	l.returnbook();
        break;
        case 9:
        	Studybooks();
        break;
        case 10:
        	magazines();
        break;
        case 11:
        	journals();
        break;
        case 12:
        	faculty();
        break;
        case 13:
        	students();
        break;
        case 14:
        	exit(0);
        break;
        default:
        cout<<"\n\n invalid option";
    }
} while (s!= 9);
    return 0;
}





