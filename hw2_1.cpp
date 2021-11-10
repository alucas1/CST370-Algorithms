/* Title: hw2_1.cpp
 * Abstract: This program reads two timestamps of two events from
 *			 a user and displays the difference between the two timestamps. 
 * Author: Alberto Lucas
 * ID: 0000
 * Date: 11/09/21
 */

#include <iostream>
#include <string>

int timeStringToSec(std::string time);
std::string timeDiff(int, int);

int main()
{
	// Initialize variables
	std::string time1, time2;

	// Get input
	std::cin >> time1 >> time2;

	// Convert input to seconds
	int t1Seconds = timeStringToSec(time1);
	int t2Seconds = timeStringToSec(time2);

	// Calculate difference and output results
	std::cout << timeDiff(t1Seconds, t2Seconds);

	return 0;
}

/*
 * Splits a string that represents time as h:m:s and converts it to seconds
 * @param  time	string that represents time as h:m:s or hh:mm:ss
 * @return int	the total time represented as seconds
 */
int timeStringToSec(std::string time)
{
	// initialize variables
	int totalSeconds = 0;
	bool hoursSaved, minutesSaved;
	hoursSaved = minutesSaved = false;
	std::string temp;

	// grabs hour, minutes, and seconds from time string and converts them to ints
	for(int i = 0; i < time.length(); i++)
	{
		if (time[i] == ':')
		{
			if(!hoursSaved) // get number of hours and add to running sum
			{
				totalSeconds += std::stoi(temp) * 3600;
				hoursSaved = true;
				temp = "";
			}
			else if(!minutesSaved) // get number of minutes and add to running sum
			{
				totalSeconds += std::stoi(temp) * 60;
				minutesSaved = true;
				temp = "";
			}
		}
		else if(i != time.length() - 1)
		{
			// add numbers to temp string before converting them to int
			temp += time[i];
		}
		else
		{
			// last iteration - save the seconds to running sum
			temp += time[i];
			totalSeconds += std::stoi(temp);
		}
	}

	return totalSeconds;
}

/*
 * Calculates the time diff between two times in seconds
 * @param  time1	The first event's time in seconds
 * @param  time2	The second event's time in seconds
 * @return string	The time difference in hh:mm:ss
 */
std::string timeDiff(int time1, int time2)
{
	// initialize variables
	std::string result = "";
	int secondsDiff = 0;

	// correct times for 24hr clock cycle - 2nd event always occurs last
	if(time1 <= time2)
		secondsDiff = time2 - time1;
	else
		secondsDiff = abs((time2 + 24 * 3600) - time1);

	// Calculate time attributes
	int hour = secondsDiff / 3600;
	int minute = (secondsDiff % 3600) / 60;
	int second = secondsDiff % 60;

	// Create time string - pad numbers <10 with 0's
	if (hour < 10)
		result += '0' + std::to_string(hour) + ':';
	else
		result += std::to_string(hour) + ':';

	if (minute < 10)
		result += '0' + std::to_string(minute) + ':';
	else
		result += std::to_string(minute) + ':';

	if (second < 10)
		result += '0' + std::to_string(second);
	else
		result += std::to_string(second);

	return result;
}