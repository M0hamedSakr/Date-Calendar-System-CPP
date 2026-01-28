#include<iostream>
#include<iomanip>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
struct Datee
{
	int Day;
	int Month;
	int Year;

};


Datee printTodayDate() {
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);

	Datee Today;
	Today.Day = ltm.tm_mday;
	Today.Month = 1 + ltm.tm_mon;
	Today.Year = 1900 + ltm.tm_year;

	return Today;
}


short readNum() {
	short Num;

	cin >> Num;
	return Num;
}
Datee READdate() {
	int Days;
	Datee datee;
	cout << "Read Day: ";
	datee.Day = readNum();
	cout << "Read Month: ";
	datee.Month = readNum();
	cout << "Read Year: ";
	datee.Year = readNum();
	return datee;
}
string getstring() {
	string x;
	getline(cin>>ws,x);
	return x;
}

bool leapyears(short Num) {
	return (Num % 400 == 0 || Num % 100 != 0 && Num % 4 == 0); /*(Num % 400 == 0) ? true : (Num % 100 == 0) ? false : (Num % 4 == 0) ? true : false;*/
}
int leapyear(short Num) {
	int days;
	days = (leapyears(Num)) ? 366 : 365;
	return days;
}
int leapMonth(short y,short Num) {
	int m;
	int a[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	(leapyears(y) && Num == 2) ? m = 29 : m = a[Num];
	return m;
}

int Second(int x, int y) {
	
	x *= 60;
	cout << left << setw(20) << "Number Of minute" << "in Month[" << y << "] is " << x<<endl;
	return 1;
}
int minute(int x, int y) {

	x *= 60;
	cout << left << setw(20) << "Number Of minute" << "in Month[" << y << "] is " << x << endl;
	return Second(x,y);
}
int hour(int x,int y) {
	;
	x = x * 24;

	cout << left << setw(20) << "Number Of hour" << "in Month[" << y << "] is " << x << endl;
	return minute(x,y);
}
int Day(int x,bool c,int m) {
	int y;
	if (c) {
		y = 29;
	}
	else
		y = 28;
	int a[] = { 0,30,y,31,30,30,30,29,30, 30,29,30,31};
	cout << left << setw(20) << "Number Of Day" << "in Month[" << m << "] is " << a[m] << endl;
	return hour(a[m],m);

}
void Date_Order() {
	Datee DD= READdate();

	int y = DD.Year;
	int yy = y;
	int m =DD.Month;
	int mm = m;

	int d = DD.Day;
	int dd = d;

	int day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	day[1] = (leapyears(y)) ? 29 : 28;
	int a = (14 - m) / 12;
	y -= a;
	m = m + (12 * a) - 2;
	d = (d + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;


	string Weekday[] = {"Sun","Mon","Tue","Wen","Thu","Fri","Str"};

	cout << endl;
	cout << left << setw(13) <<"Date"<< ":" << dd << "/" << mm << "/" << yy<<endl;
	cout << left << setw(13) << "Day Order"<<":"<<d<< endl;
	cout << left << setw(13) << "Day Name" << ":" << Weekday[d] << endl;
}
void nl(int n) {
	for (int i = 0; i < n; i++) {
		cout << "_";
	}
}
void Month_Order() {
	cout << "Enter Year:  ";
	int year = readNum();

	cout << "Enter Month (1-12):  ";
	int month = readNum();            


	int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	daysInMonth[1] = leapyears(year) ? 29 : 28;


	string Months[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	string Weekday[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	
	int mi = month - 1;
	if (mi < 0 || mi > 11) return;

	int y = year;
	int m = month;
	int d = 1;

	int a = (14 - m) / 12;
	y -= a;
	m = m + 12 * a - 2;
	int firstDow = (d + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	cout << "\n\n";
	nl(15);
	cout  << Months[mi] << " " << year ;
	nl(15);
	cout << "\n\n";
	for (int i = 0; i < 7; i++) {
		cout << Weekday[i] << " ";
	}
	cout << "\n";


	for (int i = 0; i < firstDow; i++) {
		cout << "    ";  
	}


	int totalDays = daysInMonth[mi];
	for (int day = 1; day <= totalDays; day++) {
		cout << setw(3) << day << " ";
		if ((firstDow + day) % 7 == 0) cout << "\n";
	}
	cout << "\n";
	nl(35);
	cout << "\n";
}

void Year_Order() {
	cout << "Enter Year:  ";
	int year = readNum();


	int month = 1;


	int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	daysInMonth[1] = leapyears(year) ? 29 : 28;


	string Months[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	string Weekday[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	nl(40);
	cout << "\n\n";
	cout   << "\tCalender - " << year;
	cout << endl;
	nl(40);
	for (int j = 0; j < 12; j++) {

	
	int mi = month - 1;


	int y = year;
	int m = month;
	int d = 1;

	int a = (14 - m) / 12;
	y -= a;
	m = m + 12 * a - 2;
	int firstDow = (d + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	cout << "\n\n";
	nl(15);
	cout << Months[mi] << " " << year;
	nl(15);
	cout << "\n\n";
	for (int i = 0; i < 7; i++) {
		cout << Weekday[i] << " ";
	}
	cout << "\n";


	for (int i = 0; i < firstDow; i++) {
		cout << "    ";
	}


	int totalDays = daysInMonth[mi];
	for (int day = 1; day <= totalDays; day++) {
		cout << setw(3) << day << " ";
		if ((firstDow + day) % 7 == 0) cout << "\n";
	}
	

		cout << "\n";
		nl(35);
		cout << "\n";

}
}

void addDate(int days,int year){
	while (days > (leapyears(year) ? 366 : 365)) {
		days -= (leapyears(year) ? 366 : 365);
		year++;
	}
	
	int d,i = 1;
	while (days > (d=leapMonth(year, i))) {
		days -= d;
		i++;
	}
	cout << "New Date " << days << "/" << i <<"/" << year;
	
}
int cvd(Datee DMY) {
	int Days=0;
	for (int i = 1; i < DMY.Month;i++) {
		int m = leapMonth(DMY.Year,i);
		Days += m;
	}
	Days += DMY.Day;
	return Days;


}
int newdays() {
	cout << "Read New Days: ";
	int NewDate = readNum();
	return NewDate;
}
void readDate() {
	
	Datee datee;
	cout << "Read Day: ";
	datee.Day = readNum();
	cout << "Read Month: ";
	datee.Month = readNum();
	cout << "Read Year: ";
	datee.Year = readNum();
	int Days =cvd(datee);
	Days += newdays();
	addDate(Days, datee.Year);

}

void yy(int y1,int y2) {
	if (y1 > y2)
		cout << "No Date1 is Geater Than Date2";
	else
		cout << "Yes Date1 is less Than Date2";
}
bool rightDay(Datee D) {
	int Day=leapMonth(D.Year,D.Month);
	if (Day == D.Day)
		return true;
	else
		return false;


}
bool rightMon(int m) {
	if (m == 12)
		return true;
	else
		return false;
}
Datee DateOneday(Datee D) {

	
	if (rightDay(D)) {
		if (rightMon(D.Month)) {
			D.Month = 1;
			D.Day = 1;
			D.Year += 1;
			
		}
		else
			D.Day = 1;
		D.Month += 1;
	
	}

		
	else
		D.Day += 1;
	return D;
}
int DifernceNotinclude(Datee D1, Datee D2) {
	int Days = 0;
	while (D1.Year < D2.Year) {
		Days += (leapyears(D1.Year)) ? 366 : 365;
		D1.Year++;
	}
	Days -= cvd(D1);
	Days += cvd(D2);
	return Days;
}
Datee DateADD(Datee D) {


	if (rightDay(D)) {
		if (rightMon(D.Month)) {
			D.Month = 1;
			D.Day = 1;
			D.Year += 1;

		}
		else
			D.Day = 1;
		D.Month += 1;

	}


	else
		D.Day += 1;
	return D;
}
void Date_Check(Datee DD) {
	

	int y = DD.Year;
	int yy = y;
	int m = DD.Month;
	int mm = m;

	int d = DD.Day;
	int dd = d;

	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	day[1] = (leapyears(y)) ? 29 : 28;
	int a = (14 - m) / 12;
	y -= a;
	m = m + (12 * a) - 2;
	d = (d + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;


	string Weekday[] = { "Sun","Mon","Tue","Wen","Thu","Fri","Str" };
	string DayName =Weekday[d];
	cout << "Date" << ":" << dd << "/" << mm << "/" << yy<< " Today Is "<<DayName<< endl;
	string	endweak = (DayName == "str") ? "Yes end of weak. " : "No Not end of week. ";
	cout << endweak << endl;

	string	weakend = (DayName == "Fri") ? "Yes of weakend. " : "No Not of weekend. ";
	cout <<  weakend << endl;
	cout << endl;

	
	cout << left << setw(13) << "Days until End of Weak" << ":" <<7- d << " Day(s)." <<endl;
	cout << "Days until end of month " << (leapMonth(DD.Year, DD.Month)-DD.Day)<<" Day(s)." << endl;
	cout << "Days until end of year : " << (leapyear(DD.Year) - cvd(DD)) << " Day(s)." << endl;


}
int CalcDate(Datee DD) {

	int y = DD.Year;
	int m = DD.Month;
	int d = DD.Day;

	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	day[1] = (leapyears(y)) ? 29 : 28;

	int a = (14 - m) / 12;
	y -= a;
	m = m + (12 * a) - 2;

	d = (d + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}
void Vacation(Datee D, Datee DD) {
	string Weekday[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	int startDay = CalcDate(D);

	
	int days = DifernceNotinclude(D, DD);

	cout << "Vacation From : " << Weekday[startDay]
		<< " , " << D.Day << "/" << D.Month << "/" << D.Year << endl;

	int endDay = CalcDate(DD);
	cout << "Vacation To: " << Weekday[endDay]
		<< " , " << DD.Day << "/" << DD.Month << "/" << DD.Year << endl;

	int j = 0;

	for (int k = 0; k <= days; k++) {
		int currentDay = (startDay + k) % 7;

	
		if (Weekday[currentDay] != "Fri" &&
			Weekday[currentDay] != "Sat"&& Weekday[currentDay] != "Sun") {
			j++;
		}
	}

	cout << "Actual Vacation Days is: " << j << endl;
}
void Vacation_Ends(Datee D, int Days) {
	string Weekday[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	int d = CalcDate(D);   
	int allDays = 0;     

	while (Days > 0) {
		d = d % 7;
		if (Weekday[d] != "Fri" && Weekday[d] != "Sat") {
			Days--;
		}
		allDays++;
		d++;   
	}

	
	addDate(allDays, D.Year);
}
bool DatelisafterDate2(Datee D, Datee DD) {
	return ((D.Year > DD.Year) ||( D.Year == DD.Year && D.Month > DD.Month) ||( D.Year == DD.Year && D.Month == DD.Month && D.Day > DD.Day));
}

bool DatelisabeforeDate2(Datee D, Datee DD) {
	return ((D.Year < DD.Year) || (D.Year == DD.Year && D.Month < DD.Month) || (D.Year == DD.Year && D.Month == DD.Month && D.Day < DD.Day));
}
bool DatelisabDate2(Datee D, Datee DD) {
	return (D.Year == DD.Year && D.Month == DD.Month  && D.Day == DD.Day);
}
int CompareDates(Datee D, Datee DD) {
	if (DatelisafterDate2(D, DD))
		return 1;
	else if (DatelisabeforeDate2(D, DD))
	{
		return -1;
	}
	else if (DatelisabDate2(D, DD)) {
		return 0;
	}
}
void period(Datee DS, Datee DE,Datee DDS,Datee DDE) {
	if (CompareDates(DS, DDS) == 1 && CompareDates(DS, DDE) == 1) {
		cout << "No, Periods Fit\n";

	}
	else if (CompareDates(DS, DDS) == -1 && CompareDates(DE, DDS) == -1) {
		cout << "No, Periods Fit\n";

	}
	else
		cout << "Yes, Periods Overlap\n";
}

void within_period(Datee DS, Datee DE, Datee DC) {

	if (CompareDates(DS,DC) == -1 && CompareDates(DE,DC) == 1) {
		cout << "Yes, Date is within period\n";

	}
	else
		cout << "No, Date is Without period\n";

}
bool within_periodd(Datee DS, Datee DE, Datee DC) {

	if (CompareDates(DS, DC) == -1 && CompareDates(DE, DC) == 1) {
		return true;

	}
	else
		return false;

}

void Days_Count(Datee DS, Datee DE, Datee DDS, Datee DDE) {
	if (within_periodd(DS, DE, DDS)) {
		cout << "Overlap Days Count Is:" << DifernceNotinclude(DDS, DE);

		}
	
	if (within_periodd(DS, DE, DDE)) {
		cout << "Overlap Days Count Is:" << DifernceNotinclude(DS,DDE);
	}
}
void valide_date(Datee DS) {
	int x;
	if (DS.Day < 1 || DS.Month < 1 || DS.Year < 1||DS.Month>12) {
		cout << "No, Date is a NOT valide date\n";
	}
	else if((x=leapMonth(DS.Year,DS.Month))<DS.Day){
		cout << "No, Date is a NOT valide date\n";
	}
	else {
		cout << "Yes,Date is a valide date.\n";
	}
}

void  StringToDat(string Date, Datee &DS) {
	int x = 0;
	vector <int> vec;
	while ((x = Date.find("/")) != string::npos) {
		vec.push_back(stoi(Date.substr(0, x)));
		Date.erase(0,x+1);
	}
	vec.push_back(stoi(Date));
	DS.Day = vec[0];
	DS.Month = vec[1];
	DS.Year = vec[2];


}
int main() {

	Datee DS;
	string Date;
	cout << "Please Enter Date dd/mm/yyyy?";
	Date = getstring();
	StringToDat(Date,  DS);
	cout << "\nDay : " << DS.Day;
	cout << "\nMonth : " << DS.Month;
	cout << "\nYear :" << DS.Year;


}
