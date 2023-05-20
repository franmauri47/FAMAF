#include "weather_utils.h"
#include "array_helpers.h"
#include <limits.h>

unsigned int total_rain_x_month;

int min(int a, int b){
    int res;
    if (a < b){
        res = a;
    }
    else{
        res = b;
    }
    return res;
}

int max(int a, int b){
    int res;
    if (a > b){
        res = a;
    }
    else{
        res = b;
    }
    return res;
}

int lowest_temperature(WeatherTable array) {
    int res = INT_MAX;
    for (int years = 0; years < YEARS; years++){
        for (int months = 0; months < MONTHS; months++){
            for (int days = 0; days < DAYS; days++){
                res = min(res,array[years][months][days]._min_temp);
            }
        }
    }
    return res;
}

int max_anual_temp(WeatherTable array, int year){
    int res = INT_MIN;
    for (int month = 0; month < MONTHS; month++){
        for (int day = 0; day < DAYS; day++){
            res = max(res,array[year][month][day]._max_temp);
        }
    }
    return res;    
}

void max_temp_per_year(WeatherTable array,int output[YEARS]){    
    for (int year = 0; year < YEARS; year++){
        output[year] = max_anual_temp(array, year);
    }
}

void dump_max_temp(int temperatures[YEARS]){
    for (int i=0; i < YEARS; i++){
        printf("La temperatura máxima de %d fue %d\n", i+FST_YEAR, temperatures[i]);
    }
}

void max_rainfall_month_by_year(WeatherTable array, unsigned int output[]){
    month_t max_month;
    unsigned int monthly_rain = 0u;
    unsigned int max_rain = 0u;

    for (int years = 0; years < YEARS; ++years){
        max_rain = 0u ;                                                      //cada vez que cambiamos de año, la max precipitacion es 0

        for (int months = 0; months < MONTHS; ++months){      
            monthly_rain = 0;                                               //idem pero con la precipitacion mensual
            
            for (int days = 0; days < DAYS; ++days){
                monthly_rain = monthly_rain + array[years][months][days]._rainfall;     //suma las precipitaciones de ese mes
            }

            if (monthly_rain > max_rain){                                   //si la precipitacion mensual es mayor al maximo anual hasta el momento, guardamos ese mes en max_month
                max_month = months;
            }
        }
        output[years] = max_month;                                      //guardamos los valores en el output
    }
}

void dump_rain(unsigned int rainmonth[YEARS]){
    for (int i=0;i<YEARS;i++){
        printf("El mes de mayor lluvia en %d fue %d\n",i+FST_YEAR,rainmonth[i]);
    }    
}
