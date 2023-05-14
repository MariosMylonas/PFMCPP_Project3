 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    struct Steps
    {
        void stepForward();
        int stepSize();
    };

    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;
    Steps leftFoot;
    Steps rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
    int timeRunning = distanceTraveled / howFast;
    std::cout << "the time you spend running is" << timeRunning;
}

void Person::Steps::stepForward()
{
    std::cout << "start running";
}

int Person::Steps::stepSize()
{
    int size = 18;
    return size;
}


 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */




struct Computer
{
    int ram = 16;
    int cpuCores = 8;
    int gpuCores = 8;
    int amountOfMemory = 512;
    float dailyHoursOfOperation = 8.5f;

    struct Monitor
    {
        int horizontalPixels = 3840;
        int verticalPixels = 2160;
        float inches = 40.3f;
        std::string panelType = "IPS";
        float pixelDensity = 110.15f;

        void transmitVideo(std::string connectorType = "HDMI");
        float setNitBrightness();
        void connectUsbToMonitor(bool availablePort = false);
    };

    void compileCode();
    void produceMidi();
    void streamMovies(Monitor monitor);
    void buyNewMonitor(Monitor newMonitor);
    Monitor monitor;
};

void Computer::Monitor::transmitVideo(std::string connectorType)
{
    std::cout << "connect the appropriate cable to the" << connectorType << "port"; 
}

float Computer::Monitor::setNitBrightness()
{
    float brightnessLevel = 58.2f;
    return brightnessLevel;
}

void Computer::Monitor::connectUsbToMonitor(bool availablePort)
{
    if(availablePort == true)
    {
        std::cout << "connect USB to port";
    }
    else
    {
        std::cout << "Free up a port that is not needed for the operation of the computer";
    }
}

void Computer::compileCode()
{
    bool codeDebugged = false;

    if(codeDebugged == true)
    {
        std::cout << "Run Compiler";
    }
    else
    {
        std::cout << "debug code";
    }
}

void Computer::produceMidi()
{
    bool dawRunning = true;
    if(dawRunning == true)
    {
        std::cout << "insert midi notes";
    }
    else
    {
        std::cout << "open your DAW";
    }
}

void Computer::streamMovies(Monitor existingMonitor)
{
    
    std::string name = "Name of streaming service";
    bool subscriptionPaid = true;
    if(subscriptionPaid == true)
    {
        existingMonitor.transmitVideo();
    }
    else
    {
        std::cout << "Pay the subscription";
    }
}

void Computer::buyNewMonitor(Monitor newMonitor)
{
    float newMonitorPrice = 428.12f;
    float availableMoney = 982.17f;
    float moneyLeftOver = availableMoney - newMonitorPrice;
    std::cout << "your remaining money is" << moneyLeftOver;
    newMonitor.setNitBrightness();
    monitor = newMonitor;
    
}

struct Synthesizer
{
    int numberOfKeys = 61;
    int numberOfOscillators = 4;
    int numberOfLfos = 2;
    double outputVolume = 72.8;
    float attackTime = 0.31f;

    float generateAudio(float inputFrequency);
    void filterFrequencies(float cutOffFrequency);
    void changeTheAudioEnvelope();
};

float Synthesizer::generateAudio(float inputFrequency)
{
    float frequencyModulation = 628.12f;
    float outputFrequency = inputFrequency * frequencyModulation;
    return outputFrequency;
}

void Synthesizer::filterFrequencies(float cutOfFrequency)
{
    std::cout << "the cut off frequency is" << cutOfFrequency; 
}

void Synthesizer::changeTheAudioEnvelope()
{
    float newAttackTime = 0.12f;
    attackTime = newAttackTime;
}


struct BasketballCourt
{
    int numberOfBasketballs = 41;
    int numberOfSeats = 25000;
    float cafeteriaProfits = 684.18f;
    int administraionPersonelSize = 14;
    int teamSize = 12;

    struct EventsSchedule
    {
        int bookedDaysPerMonth = 24;
        float percentageOfBasketballGamesVsOtherEvents = 61.2f;
        int numberOfCancellations = 3;
        std::string eventCoordinator = "Stella";
        std::string appForOrganizing = "Notion";

        void cancelAllMondayEvents(int numberOfMondayEvents);
        void rescheduleAllWednesdayEvents(int numberOfWednesdayEvents);
        void organizeNextMonthsSchedule();
    };

    void hostBasketballGames(EventsSchedule scheduledGameDay);
    void hostSportEvents();
    float sellTickets(float ticketPrice);

    void scheduleNewGameDay(EventsSchedule newGameDay);
    EventsSchedule scheduledGameDay;
};

void BasketballCourt::EventsSchedule::cancelAllMondayEvents(int numberOfMondayEvents)
{
    std::cout << numberOfMondayEvents << "events have been cancelled";
}

void BasketballCourt::EventsSchedule::rescheduleAllWednesdayEvents(int numberOfWednesdayEvents)
{
    std::cout << numberOfWednesdayEvents << "events have been rescheduled";
}

void BasketballCourt::EventsSchedule::organizeNextMonthsSchedule()
{
    int numberOfNextMonthsEvents = 18;
    std::cout << "organize" << numberOfNextMonthsEvents << "next month";
}

void BasketballCourt::hostBasketballGames(EventsSchedule gameDay)
{
    gameDay.rescheduleAllWednesdayEvents(2);
}

void BasketballCourt::hostSportEvents()
{
    std::string nameOfEvent = "event name";
    std::string eventDate = "date";
    std::cout << nameOfEvent << "will take place on" << eventDate;
}

float BasketballCourt::sellTickets(float ticketPrice)
{
    int numberOfTicketsSold = 651.0;
    float ticketsFloat;
    ticketsFloat = float(numberOfTicketsSold);
    float earnings = ticketPrice * ticketsFloat;
    return earnings;
}

void BasketballCourt::scheduleNewGameDay(EventsSchedule newGameDay)
{
    newGameDay.organizeNextMonthsSchedule();
    scheduledGameDay = newGameDay;
}

struct Cafeteria
{
    float priceOfCoffee = 3.2f;
    int amountOfEmployees = 8;
    float priceOfSandwich = 4.8f;
    float amountOfRentPerMonth = 1028.12f;
    int numberOfCustomersPerMonth = 964;

    float sellCoffee(float coffeePrice);
    void providePlaceForFriendlyMeetings();
    float sellSnacks(float snacksPrice);
};

float Cafeteria::sellCoffee(float coffeePrice)
{
    int numberOfCoffeesSold = 132;
    float coffeesFloat;
    coffeesFloat = float(numberOfCoffeesSold);
    float profit = coffeePrice * coffeesFloat;
    return profit;
}

void Cafeteria::providePlaceForFriendlyMeetings()
{
    int time = 8;
    std::string day = "Friday";
    std::cout << "the meeting will take place on" << day << "at" << time << "o'clock";
}

float Cafeteria::sellSnacks(float snacksPrice)
{
    int numberOfSnacksSold = 44;
    float snacksFloat;
    snacksFloat = float(numberOfSnacksSold);
    float amountEarned = snacksPrice * snacksFloat;
    return amountEarned; 
}


struct AudioDepartment
{
    int personelSize = 68;
    float allocatedBudget = 12832.4f;
    std::string departmentHead = "John";
    int numberOfStudios = 3;
    std::string departmentLogo = "all Audio";

    void implementAudioProductions();
    void testAudioSoftware();
    void recordAudio(int numberOfMicrophones);
};

void AudioDepartment::implementAudioProductions()
{
    std::cout << "produce film audio and orchestral music";
}

void AudioDepartment::testAudioSoftware()
{
    bool softwareWorking = true;
    if(softwareWorking == true)
    {
        std::cout << "anounce sales department";
    }
    else
    {
        std::cout << "keep working on the software";
    }
}

void AudioDepartment::recordAudio(int numberOfMicrophones)
{
    std::cout << "record" << numberOfMicrophones << "different sources simultaneously";
}

struct VisualDepartment
{
    int numberOfVideocameras = 11;
    int numberOfLightProjectors = 8;
    std::string departmentLogo = "all Video";
    std::string preferedEditingSoftware = "davinci resolve";
    std::string preferedCloudStorageSolution = "dropbox for business";

    void createAnimation();
    void colorGradeVideoFootage();
    void editShortFilms();
};

void VisualDepartment::createAnimation()
{
    int numberOfAnimators = 12;
    std::cout << "employ" << numberOfAnimators << "people to create the animation";
}

void VisualDepartment::colorGradeVideoFootage()
{
    int numberOfColorsAvailable = 1231232;
    std::string colorProfile = "RGB";
    std::cout << "use the" << numberOfColorsAvailable << "available colours in the" << colorProfile << "profile";
}

void VisualDepartment::editShortFilms()
{
    float filmLength = 32.42f;
    float rawFootageLength = 123.51f;
    std::cout << "edit the" << rawFootageLength << "minutes into a" << filmLength << "minutes long film";
}

struct Sales
{
    int softwareCopiesSold = 19842;
    float softwarePrice = 98.12f;
    int numberOfSteadyClients = 84;
    int numberOfSubscribersToCloudSolutions = 81;
    std::string departmentEmailAddress = "companymail@gmail.com";

    float sellSoftware(float softwarePrice);
    void reachOutToPotentialClients();
    void negotiateBetterDealsForLargeContracts();
};

float Sales::sellSoftware(float softwareCopyPrice)
{
    int numberOfSoftwareCopiesSold = 144;
    float copiesFloat;
    copiesFloat = float(numberOfSoftwareCopiesSold);
    float profitMade = softwareCopyPrice * copiesFloat;
    return profitMade;    
}

void Sales::reachOutToPotentialClients()
{
    int clientNumber = 05512;
    std::cout << "call at" << clientNumber << "and sell the software";
}

void Sales::negotiateBetterDealsForLargeContracts()
{
    float contractPrice = 124.12f;
    float desiredPrice = 128.19f;
    std::cout << "sell the deal at" << desiredPrice << "from" << contractPrice;
}

struct RndDevelopment
{
    int numberOfLaboratories = 4;
    std::string preferedProgrammingLanguage = "C++";
    float availableFunding = 14121.5f;
    std::string preferedAcademicBackground = "Master's degree";
    int totalNumberOfProgrammingLanguagesUsed = 5;

    void developSoftware();
    void implementNewAlgorithms();
    void researchHumanPerceptionOfAudio();
};

void RndDevelopment::developSoftware()

{
    bool researchFinished = true;
    if(researchFinished == true)
    {
        std::cout << "start developing";
    }
    else
    {
        std::cout << "keep researching";
    }    
}

void RndDevelopment::implementNewAlgorithms()
{
    bool algorithmEffective = true;
    if(algorithmEffective == true)
    {
        std::cout << "implement into research";
    }
    else
    {
        std::cout << "keep optimizing";
    }      
}

void RndDevelopment::researchHumanPerceptionOfAudio()
{
    int numberOfPsychoacousticTests = 12;
    std::cout << "implement" << numberOfPsychoacousticTests << "tests";
}

struct FinanceAndAdvertising
{
    int numberOfEmployees = 28;
    float employeeSalary = 62850.4f;
    float managerSalary = 81372.9f;
    int numberOfSocialMediaPlatformsUsedForAdvertising = 11;
    std::string departmentHead = "Mary";

    void advertiseCompanyProductsOnSocialMedia();
    void createCompanyLogo();
    float payTheEmployees(float employeeSalary, int numberOfEmployees);
};

void FinanceAndAdvertising::advertiseCompanyProductsOnSocialMedia()
{
    std::string mainPlatform = "platform";
    int desiredViews = 19283;
    std::cout << "advertise on" << mainPlatform << "until you reach" << desiredViews << "views";
}

void FinanceAndAdvertising::createCompanyLogo()
{
    std::string wordsOnLogo = "audiovisual";
    std::cout << "create a logo based on" << wordsOnLogo;
}

float FinanceAndAdvertising::payTheEmployees(float employeesSalary, int totalNumberOfEmployees)
{
    float employeesFloat;
    employeesFloat = float(totalNumberOfEmployees);
    float amountPaid = employeesSalary * employeesFloat;
    return amountPaid;
}
 
struct AudiovisualCompany
{
    AudioDepartment audioDepartment;
    VisualDepartment visualDepartment;
    Sales sales;
    RndDevelopment rndDevelopment;
    FinanceAndAdvertising financeAndAdvertising;

    void createAudiovisualContent();
    void developNewAudiovisualSoftware();
    float sellProductsToCustomers(float softwarePrice, int softwarePiecesSold, int numberOfSubscribersToCloudSolutions, float subscriptionPrice);
};

void AudiovisualCompany::createAudiovisualContent()
{
    int numberOfUpcomingProductions = 8;
    std::cout << "develop content for" << numberOfUpcomingProductions << "productions";
}

void AudiovisualCompany::developNewAudiovisualSoftware()
{
    int numberOfWorkingEmployeesOnProject = 12;
    int numberOfTasksToBeDone = 92;
    std::string projectManager = "Tom";
    std::cout << "employ" << projectManager << "to allocate to the" << numberOfWorkingEmployeesOnProject << "employees the" << numberOfTasksToBeDone << "tasks required";
}

float AudiovisualCompany::sellProductsToCustomers(float softwarePrice, int softwarePiecesSold, int numberOfSubscribersToCloudSolutions, float subscriptionPrice)
{
    float softwarePiecesFloat;
    softwarePiecesFloat = float(softwarePiecesSold);
    float cloudSubscribersFLoat;
    cloudSubscribersFLoat = float(numberOfSubscribersToCloudSolutions);
    float totalCompanyEarnings = softwarePrice * softwarePiecesFloat + subscriptionPrice * cloudSubscribersFLoat;
    return totalCompanyEarnings;
}




int main()
{
    std::cout << "good to go!" << std::endl;
}
