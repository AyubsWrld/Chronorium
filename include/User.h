#ifndef USER_H
#define USER_H

#include <vector>
#include <string>
#include <iostream>
#include "processState.h"


class User {

    //Member variables
    std::vector<App*>   m_applications      ;
    std::string         m_name              ;
    std::string         m_email             ;
    std::uint8_t        m_id                ;

public:

    //Constructor & Destructor 
    User(const std::string& name = "", const std::string& email = "");
    ~User();

    //Member functions
    const std::string& getName() const;
    void setName(const std::string& name);
    const std::string& getEmail() const;
    void setEmail(const std::string& email);

    void instantiateApplication(std::string appName)  ;
    App * getApplicationFirst() ; 
    void runApplications() const ;
};

#endif // USER_H
