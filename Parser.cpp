#include "Parser.h"

using namespace libxl;

Parser::Parser() {
}

void Parser::parseFile(int day, int hour) {

    this->stations.clear();
    Station s;
    Book* book1 = xlCreateBook();
    const char* string;
    float longitude;  
    float latitude;
    int value;

    if(book1) {

        if(book1->load("mesures.xls")) {

            Sheet* sheet1 = book1->getSheet(0);
            if(sheet1) {

                for (int i = 0; i < 25; i++) {
                    longitude = sheet1->readNum(i, 0);
                    latitude = sheet1->readNum(i, 1);
                    value  = sheet1->readNum(i, 3 + (day - 1)*24 + hour);
                    string = sheet1->readStr(i, 3 + (day - 1)*24 + hour);
                    if ((value != 0) || (value == 0 && string == NULL)) {
                        s = Station(longitude, latitude, (float) value);
                        this->stations.push_back(s);
                        std::cout << "Longitude : " << longitude << " Latitude : " << latitude << " Résultat : " <<  value << std::endl;
                    }
                }
            }
        }

        book1->release();
    }

    Book* book2 = xlCreateBook();

    if(book2) {              

        if(book2->load("mesures.xls")) {

            Sheet* sheet2 = book2->getSheet(0);
            if(sheet2) {   

                for (int i = 25; i < 49; i++) {
                    longitude = sheet2->readNum(i, 0);
                    latitude = sheet2->readNum(i, 1);
                    value  = sheet2->readNum(i, 3 + (day - 1)*24 + hour);
                    string = sheet2->readStr(i, 3 + (day - 1)*24 + hour);
                    if ((value != 0) || (value == 0 && string == NULL)) {
                        s = Station(longitude, latitude, (float)value);
                        this->stations.push_back(s);
                        std::cout << "Longitude : " << longitude << " Latitude : " << latitude << " Résultat : " <<  value << std::endl;
                    }
                }
            }
        }

        book2->release();   
    }
}


