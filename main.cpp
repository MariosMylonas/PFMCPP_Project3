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



/*
Thing 1) computer

 */
struct Computer
{
    //5 properties:
    //    1) amount of ram (int)
    int ram = 16;
    //    2) CPU cores (int)
    int cpuCores = 8;
    //    3) GPU cores (int)
    int gpuCores = 8;
    //    4) amount of memory (int)
    int amountOfMemory = 512;
    //    5) daily hours of operation (float)
    float dailyHoursOfOperation = 8.5f;

    //this is the nested UDT
    struct Monitor
    {
        int horizontalPixels = 3840;
        int verticalPixels = 2160;
        float inches = 40.3f;
        std::string panelType = "IPS";
        float pixelDensity = 110.15f;

        void transmitVideo(std::string connectorType = "HDMI");
        float setNitBrightness(); //returns the nit brightness value
        void connectUsbToMonitor(bool availablePort = false);
    };

    //3 things it can do:
    //    1) compile code
    void compileCode();
    //    2) produce MIDI
    void produceMidi();
    //    3) stream movies
    void streamMovies(Monitor monitor);

    void buyNewMonitor(Monitor newMonitor);
    Monitor monitor;
};

/*
Thing 2) synthesizer

 */
struct Synthesizer
{
    //5 properties:
    //    1) number of keys (int)
    int numberOfKeys = 61;
    //    2) number of oscillators (int)
    int numberOfOscillators = 4;
    //    3) number of LFOs (int)
    int numberOfLfos = 2;
    //    4) output volume (double)
    double outputVolume = 72.8;
    //    5) Attack time (float)
    float attackTime = 0.31f;
    //3 things it can do:
    //    1) generate audio
    void generateAudio(float inputFrequency);
    //    2) fitler frequencies
    void filterFrequencies(float cutOffFrequency);
    //    3) change the audio's envelope
    void changeTheAudioEnvelope();
};

/*
Thing 3) basketball court

 */
struct BasketballCourt
{
    //5 properties:
    //    1) number of basketballs (int)
    int numberOfBasketballs = 41;
    //    2) nubmer of seats (int)
    int numberOfSeats = 25000;
    //    3) cafeteria profits (float)
    float cafeteriaProfits = 684.18f;
    //    4) administration personel size (int)
    int administraionPersonelSize = 14;
    //    5) team size (int)
    int teamSize = 12;

    //this is the nested UDT
    struct EventsSchedule
    {
        int bookedDaysPerMonth = 24;
        float percentageOfBasketballGamesVsOtherEvents = 61.2f;
        int numberOfCancellations = 3;
        std::string eventCoordinator = "Stella";
        std::string appForOrganizing = "Notion";

        void cancelAllMondayEvents(int numberOfMondayEvents);
        void rescheduleAllWendesdayEvents(int numberOfWendesdayEvents);
        void organizeNextMonthsSchedule();
    };

    //3 things it can do:
    //    1) host basketball games
    void hostBasketballGames(EventsSchedule scheduledGameDay);
    //    2) host sport events
    void hostSportEvents();
    //    3) sell tickets
    float sellTickets(float ticketPrice); //returns the amount of money earned
    void scheduleNewGameDay(EventsSchedule newGameDay);
    EventsSchedule scheduledGameDay;
};

/*
Thing 4) cafeteria

 */
struct Cafeteria
{
    //5 properties:
    //    1) price of coffee (float)
    float priceOfCoffee = 3.2f;
    //    2) amount of emplyees (int)
    int amountOfEmployees = 8;
    //    3) price of sandwich (float)
    float priceOfSandwich = 4.8f;
    //    4) amount of rent per month (float)
    float amountOfRentPerMonth = 1028.12f;
    //    5) number of customers per month (int)
    int numberOfCustomersPerMonth = 964;
    //3 things it can do:
    //    1) sell coffee
    float sellCoffee(float coffeePrice); //returns the amount of money earned
    //    2) provide a place for friendly meetings
    void providePlaceForFriendlyMeetings();
    //    3) sell snacks
    float sellSnacks(float snacksPrice); //returns the amount of money earned

};

/*
Thing 5) audio department

 */
struct AudioDepartment
{
    //5 properties:
    //    1) personel size (int)
    int personelSize = 68;
    //    2) allocated budget (float)
    float allocatedBudget = 12832.4f;
    //    3) department head (std::string)
    std::string departmentHead = "John";
    //    4) number of studios (int)
    int numberOfStudios = 3;
    //    5) department logo (std::string)
    std::string departmentLogo = "all Audio";
    //3 things it can do:
    //    1) implement audio productions
    void implementAudioProductions();
    //    2) test audio software
    void testAudioSoftware();
    //    3) record audio
    void recordAudio(int numberOfMicrophones);

};

/*
Thing 6) visual department

 */
struct VisualDepartment
{
    //5 properties:
    //    1) number of videocameras (int)
    int numberOfVideocameras = 11;
    //    2) number of light projectors (int)
    int numberOfLightProjectors = 8;
    //    3) department logo (std::string)
    std::string departmentLogo = "all Video";
    //    4) prefered editing software (std::string)
    std::string preferedEditingSoftware = "davinci resolve";
    //    5) prefered cloud storage solution (std::string)
    std::string preferedCloudStorageSolution = "dropbox for business";
    //3 things it can do:
    //    1) create animation
    void createAnimation();
    //    2) color grade video footage
    void colorGradeVideoFootage();
    //    3) edit short films
    void editShortFilms();

};

/*
Thing 7) sales

 */
struct Sales
{
    //5 properties:
    //    1) software copies sold (int)
    int softwareCopiesSold = 19842;
    //    2) software price (float)
    float softwarePrice = 98.12f;
    //    3) number of steady clients (int)
    int numberOfSteadyClients = 84;
    //    4) number of subscribers to cloud solutions (int)
    int numberOfSubscribersToCloudSolutions = 81;
    //    5) department email address (std::string)
    std::string departmentEmailAddress = "companymail@gmail.com";
    //3 things it can do:
    //    1) sell software
    float sellSoftware(float softwarePrice); //returns the amount of money earned
    //    2) reach out to potential clients
    void reachOutToPotentialClients();
    //    3) negotiate better deals for large contracts
    void negotiateBetterDealsForLargeContracts();

};

/*
Thing 8) RnD department

 */
struct RndDevelopment
{
    //5 properties:
    //    1) number of laboratories (int)
    int numberOfLaboratories = 4;
    //    2) prefered programming language (std::string)
    std::string preferedProgrammingLanguage = "C++";
    //    3) available funding (float)
    float availableFunding = 14121.5f;
    //    4) prefered academic background (std::string)
    std::string preferedAcademicBackground = "Master's degree";
    //    5) total number of programming languages used (int)
    int totalNumberOfProgrammingLanguagesUsed = 5;
    //3 things it can do:
    //    1) develop software
    void developSoftware();
    //    2) implement new algorithms
    void implementNewAlgorithms();
    //    3) reseach human perception of audio
    void researchHumanPerceptionOfAudio();

};

/*
Thing 9) finance and advertising

 */
struct FinanceAndAdvertising
{
    //5 properties:
    //    1) number of employees (int)
    int numberOfEmployees = 28;
    //    2) employee salary (float)
    float employeeSalary = 62850.4f;
    //    3) manager salary (float)
    float managerSalary = 81372.9f;
    //    4) number of social media platforms used for advertising (int)
    int numberOfSocialMediaPlatformsUsedForAdvertising = 11;
    //    5) department head (std::string)
    std::string departmentHead = "Mary";
    //3 things it can do:
    //    1) advertise the companie's products on social media
    void advertiseCompanyProductsOnSocialMedia();
    //    2) create the company logo
    void createCompanyLogo();
    //    3) pay the employees
    float payTheEmployees(float employeeSalary, int numberOfEmployees); //returns the amount of money paid to the employes

};

/*
Thing 10) audiovisual company

*/
 
struct audiovisualCompany
{
    //5 properties:
    //    1) audio department
    AudioDepartment audioDepartment;
    //    2) visual department
    VisualDepartment visualDepartment;
    //    3) sales
    Sales sales;
    //    4) RnD department
    RndDevelopment rndDevelopment;
    //    5) finance and advertising
    FinanceAndAdvertising financeAndAdvertising;
    //3 things it can do:
    //    1) create audiovisual content
    void createAudiovisualContent();
    //    2) develop new audiovisual software
    void developNewAudiovisualSoftware();
    //    3) sell products to customers
    float sellProductsToCustomers(float softwarePrice, int softwarePiecesSold, int numberOfSubscribersToCloudSolutions, float subscriptionPrice);  //returns the total earnings  

};








int main()
{
    std::cout << "good to go!" << std::endl;
}
