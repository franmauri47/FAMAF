#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "array_helpers.h"

int min(int a, int b);
/*return the minimal between "a" and "b"*/

int max(int a, int b);
/*return the maximum between "a" and "b"*/

int lowest_temperature(WeatherTable array);
/*Return the lowest temperature registered in the timelapse indicated by the array*/

int max_anual_temp(WeatherTable array, int year);
/*Return the highest temperature resgistered in array according to the year passed by parameter*/

void max_temp_per_year(WeatherTable array,int output[YEARS]);
/*fill the output array with the highests temperatures registered per year in the incoming array*/

void dump_max_temp(int temperatures[YEARS]);
/*Print the temperatures from the right up function*/

void max_rainfall_month_by_year(WeatherTable array, unsigned int output[]);

void dump_rain(unsigned int rainmonth[YEARS]);

#endif