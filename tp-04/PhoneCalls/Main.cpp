#include "Person.h"
#include "Phone.h"
#include "HomePhone.h"
#include "MobilePhone.h"

int main()
{
    Person paul { "Paul", 3 };

    HomePhone home_phone { paul };
    home_phone.ring();                  // Hi! Paul on the phone.

    HomePhone close_phone { paul, 3 };
    close_phone.ring();					// Hi! Paul on the phone.

    HomePhone far_phone { paul, -10 };
    far_phone.ring();                   // This is the voicemail of Paul. Please leave a message.

    MobilePhone mobile_phone { paul };
    mobile_phone.ring();                // Hi! Paul on the phone.
    
    MobilePhone far_mobile_phone { paul, -10 };
    far_mobile_phone.ring();            // This is the voicemail of Paul. Please leave a message.

    return 0;
}
