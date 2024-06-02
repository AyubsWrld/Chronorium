#include "User.h"


User::User( const std::string& name, const std::string& email)
    : m_name(name), m_email(email) {
    std::cout << "User object created, name: " << m_name << std::endl;
}

User::~User() {
    // Implement any necessary cleanup
}

const std::string& User::getName() const {
  return m_name;
}

void User::setName(const std::string& name) {
  m_name = name;
}

const std::string& User::getEmail() const {
  return m_email;
}

void User::setEmail(const std::string& email) {
  m_email = email;
}

void User::instantiateApplication(std::string appName) {
  App * app = new App(appName) ; 
  m_applications.push_back(app);
  std::cout << "Application: " << app->getName() << " Instantiated" << std::endl;
}


App * User::getApplicationFirst()
{
  return m_applications[0] ; 
}


void User::runApplications() const
{
    std::vector<std::thread> threads;
    for (const auto& app : m_applications)
    {
        threads.emplace_back(handleProcesses, app->getName(), app);
    }

    for (auto& thread : threads)
    {
        if (thread.joinable())
        {
            thread.join();
        }
    }

    std::cout << "No more running processes" << std::endl;
}
