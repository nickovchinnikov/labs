#include "User.cpp"
#include <memory>

using namespace std;

int main() {
    User user1("JohnDoe", "john@example.com", 25);
    user1.printInfo();

    RegisteredUser user2("JaneSmith", "jane@example.com", 30, "password123");
    user2.printInfo();

    AdminUser user3("AdminUser", "admin@example.com", 40, "Administrator");
    user3.printInfo();

    unique_ptr<RegisteredUser> user4 = make_unique<RegisteredUser>("MikeBrown", "mike@example.com", 35, "mikepassword");
    user4->printInfo();

    shared_ptr<AdminUser> user5 = make_shared<AdminUser>("SuperAdmin", "superadmin@example.com", 45, "Super Administrator");
    user5->printInfo();

    return 0;
}
