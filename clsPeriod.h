#pragma once
#include <iostream>
#include "clsDate.h";
using namespace std;

class clsPeriod{

public:
	clsDate StartDate;
	clsDate EndDate;



	clsPeriod(clsDate StartDate, clsDate EndDate) {
		this->StartDate = StartDate;
		this->EndDate = EndDate;
	}

	static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
	{

		if (
			clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enCompareResult::Before
			||
			clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enCompareResult::After
			)
			return false;
		else
			return true;

	}


	bool IsOverLapWith(clsPeriod Period2)
	{
		return IsOverlapPeriods(*this, Period2);
	}

	void Print()
	{
		cout << "Period Start: ";
		StartDate.Print();


		cout << "Period End: ";
		EndDate.Print();


	}

	static short PeriodLengthInDays(clsPeriod Period, bool IncludeEndDay = false) {

		return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);

	}

	short PeriodLengthInDays() {
		return PeriodLengthInDays(*this);
	}

	static bool IsDateInPeriod(clsDate Date, clsPeriod Period) {


		//return (IsDate1LessThanDate2(Period.StartDate, Date) &&IsDate1AfterDate2(Period.EndDate, Date));
		return !(clsDate::CompareDates(Date, Period.StartDate) == clsDate::enCompareResult::Before
			||
			clsDate::CompareDates(Date, Period.EndDate) == clsDate::enCompareResult::After);
	}

	static short CountOverlapDays(clsPeriod Period1, clsPeriod Period2) {
		int Period1Length = PeriodLengthInDays(Period1, true);
		int Period2Length = PeriodLengthInDays(Period2, true);

		int countlapdays = 0;
		if (!IsOverlapPeriods(Period1, Period2))
			return 0;

		if (Period1Length < Period2Length) {
			while (clsDate::IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate)) {
				if (IsDateInPeriod(Period1.StartDate, Period2))
					countlapdays++;

				Period1.StartDate = clsDate::IncreaseDateByOneDay(Period1.StartDate);

			}


		}
		else {
			while (clsDate::IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate)) {
				if (IsDateInPeriod(Period2.StartDate, Period1))
					countlapdays++;

				Period2.StartDate = clsDate::IncreaseDateByOneDay(Period2.StartDate);

			}
		}
		return countlapdays;


	}

	short CountOverlapDays(clsPeriod Period2) {
		return CountOverlapDays(*this, Period2);
	}

};

