/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.





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
    float numberOfTicketsSold = 651.0f;
    float earnings = ticketPrice * numberOfTicketsSold;
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
    float numberOfCoffeesSold = 132.0f;
    float profit = coffeePrice * numberOfCoffeesSold;
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
    float numberOfSnacksSold = 44.0f;
    float amountEarned = snacksPrice * numberOfSnacksSold;
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
    float numberOfSoftwareCopiesSold = 144.0f;
    float profitMade = softwareCopyPrice * numberOfSoftwareCopiesSold;
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
    float payTheEmployees(float employeeSalary, float numberOfEmployees);
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

float FinanceAndAdvertising::payTheEmployees(float employeesSalary, float totalNumberOfEmployees)
{
    float amountPaid = employeesSalary * totalNumberOfEmployees;
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
    float sellProductsToCustomers(float softwarePrice, float softwarePiecesSold, float numberOfSubscribersToCloudSolutions, float subscriptionPrice);
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

float AudiovisualCompany::sellProductsToCustomers(float softwarePrice, float softwarePiecesSold, float numberOfSubscribersToCloudSolutions, float subscriptionPrice)
{
    float totalCompanyEarnings = softwarePrice * softwarePiecesSold + subscriptionPrice * numberOfSubscribersToCloudSolutions;
    return totalCompanyEarnings;
}




int main()
{
    Example::main();
    
    
    std::cout << "good to go!" << std::endl;
}
