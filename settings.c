// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"

void settingsSwitchHub () {
    screenClear ();

    bannerFullBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Settings");
    bannerBlankBorderTextCen ("________");
    bannerFullBorder ();
    for ( int i = 0; i < 5; i++ )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("What do you want to do?");

    for ( int i = 0; i < 2; i++ )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Authentication");
    bannerBlankBorderTextCen ("______________");
    bannerBlankBorderTextCen ("1. Change Password");

    for ( int i = 0; i < 2; i++ )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Storefront");
    bannerBlankBorderTextCen ("__________");
    bannerBlankBorderTextCen ("2. Change store name");
    bannerBlankBorderTextCen ("3. Change store address");

    for ( int i = 0; i < 2; i++ )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Others");
    bannerBlankBorderTextCen ("______");
    bannerBlankBorderTextCen ("4. List of contributors");
    bannerBlankBorderTextCen ("5. cat.gif");

    for ( int i = 0; i < 7; i++ )
        bannerBlankBorder ();

    if (errorResponse == 1){
       bannerBlankBorderTextCen ("Invalid response. Please try again.");
    } else{
        bannerBlankBorder ();
    }

    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'Q' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    char flag;
    scanf (" %c", &flag);
    errorResponse = 0;

    switch ( toupper (flag)) {

        case ('1'):
            settingUpdatePasswordInterface ();
            return;

        case ('2'):
            settingUpdateStoreNameInterface();
            return;

        case ('3'):
            settingUpdateStoreAddressInterface ();
            return;

        case ('4'):
            settingContributorList ();
            return;

        case ('5'):
            settingCat ();
            return;

        case ('B'):
            switchHub ();
            break;

        case ('Q'):
            terminate ();
            break;

        default:
            errorResponse = 1;
            settingsSwitchHub ();
            break;

    }
}

void settingUpdatePasswordInterface () {
    char oldPassword[MAX_LNG_TEXT], newPasswordBar1[MAX_LNG_TEXT], newPasswordBar2[MAX_LNG_TEXT], flag;
    char firstname[MAX_LNG_TEXT], lastname[MAX_LNG_TEXT], username[MAX_LNG_TEXT], password[MAX_LNG_TEXT], barcodeToken[MAX_LNG_TOKEN];
    int role;
    personnelSelectById(Session.user.id, firstname, lastname, &role, username, password, barcodeToken);
    screenClear ();
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Settings");
    bannerFullBorder ();
    for (int i = 0;i<10;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Please Type Old Password");
    bannerBlankBorder ();

    for (int i = 0;i<22;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    scanf("%s", oldPassword);
    while (1){
        if (strcmp(oldPassword, password) == 0){
            //Enter First password
            screenClear ();
            bannerFullBorder ();
            bannerBlankBorderTextCen ("Settings");
            bannerFullBorder ();
            for (int i = 0;i<10;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Your password was Correct");
            bannerBlankBorder ();

            for (int i = 0;i<22;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Please type your new password...");
            bannerFullBorder ();

            bannerUserInput ();
            scanf("%s", newPasswordBar1);

            //Enter Second password
            screenClear ();
            bannerFullBorder ();
            bannerBlankBorderTextCen ("Settings");
            bannerFullBorder ();
            for (int i = 0;i<10;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Test");
            bannerBlankBorder ();

            for (int i = 0;i<22;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Please type new password again...");
            bannerFullBorder ();

            bannerUserInput ();
            scanf("%s", newPasswordBar2);

            if (strcmp(newPasswordBar1, newPasswordBar2) == 0){
                personnelUpdatePassword (Session.user.id, newPasswordBar1);
                screenClear ();
                bannerFullBorder ();
                bannerBlankBorderTextCen ("Settings");
                bannerFullBorder ();
                for (int i = 0;i<10;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Change Password success");
                bannerBlankBorder ();

                for (int i = 0;i<22;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
                scanf(" %c", &flag);
                if (flag == 'b' || flag == 'B'){
                    settingsSwitchHub ();
                }
                else{
                    terminate (); 
                }
            }
            else{
                screenClear ();
                bannerFullBorder ();
                bannerBlankBorderTextCen ("Settings");
                bannerFullBorder ();
                for (int i = 0;i<10;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Password not same");
                bannerBlankBorderTextCen ("Please type same password");
                bannerBlankBorder ();

                for (int i = 0;i<21;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
                scanf(" %c", &flag);
                if (flag == 'b' || flag == 'B'){
                    settingsSwitchHub ();
                }
                else{
                    terminate (); 
                }
            }
        }
        else{
            screenClear ();
            bannerFullBorder ();
            bannerBlankBorderTextCen ("Settings");
            bannerFullBorder ();
            for (int i = 0;i<10;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Password was Incorrect !");
            bannerBlankBorder ();

            for (int i = 0;i<22;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Please type your password again... | Type 'B' to back");
            bannerFullBorder ();

            bannerUserInput ();
            scanf("%s", oldPassword);
            if (tolower(oldPassword[0]) == 'b' && strlen(oldPassword) == 1){
                settingsSwitchHub ();
            }
        }
    }
}

void settingUpdateStoreNameInterface () {
    char newstoreName[MAX_LNG_TEXT], flag;
    screenClear ();
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Settings");
    bannerFullBorder ();
    for (int i = 0;i<10;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Your current Storename");
    bannerBlankBorder ();
    bannerBlankBorderTextCen (Setting.storeName);
    bannerBlankBorder ();

    for (int i = 0;i<20;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Please enter new storename | Type 'B' to Back");
    bannerFullBorder ();

    bannerUserInput ();
    scanf(" %[^\n]", newstoreName);
    if (tolower(newstoreName[0]) == 'b' && strlen(newstoreName) == 1){
        settingsSwitchHub ();
    }
    else{
        settingUpdateStoreName(newstoreName);
        screenClear ();
        bannerFullBorder ();
        bannerBlankBorderTextCen ("Settings");
        bannerFullBorder ();
        for (int i = 0;i<10;i++)
            bannerBlankBorder ();
        bannerBlankBorderTextCen ("Your storename has been changed to");
        bannerBlankBorder ();
        bannerBlankBorderTextCen (newstoreName);
        bannerBlankBorder ();

        for (int i = 0;i<20;i++)
            bannerBlankBorder ();
        bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
        bannerFullBorder ();
        bannerUserInput ();
        scanf(" %c", &flag);
        if (tolower(flag) == 'b'){
            settingsSwitchHub ();
        }
        else{
            terminate();
        }
    }
}

void settingUpdateStoreAddressInterface () {
    char newstoreAddress[MAX_LNG_TEXT], flag;
    screenClear ();
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Settings");
    bannerFullBorder ();
    for (int i = 0;i<10;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Your current StoreAddress");
    bannerBlankBorder ();
    bannerBlankBorderTextCen (Setting.storeAddress);
    bannerBlankBorder ();

    for (int i = 0;i<20;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Please enter new storeaddress | Type 'B' to Back");
    bannerFullBorder ();

    bannerUserInput ();
    scanf(" %[^\n]", newstoreAddress);
    if (tolower(newstoreAddress[0]) == 'b' && strlen(newstoreAddress) == 1){
        settingsSwitchHub ();
    }
    else{
        settingUpdateAddress(newstoreAddress);
        screenClear ();
        bannerFullBorder ();
        bannerBlankBorderTextCen ("Settings");
        bannerFullBorder ();
        for (int i = 0;i<10;i++)
            bannerBlankBorder ();
        bannerBlankBorderTextCen ("Your storeadress has been changed to");
        bannerBlankBorder ();
        bannerBlankBorderTextCen (newstoreAddress);
        bannerBlankBorder ();

        for (int i = 0;i<20;i++)
            bannerBlankBorder ();
        bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
        bannerFullBorder ();
        bannerUserInput ();
        scanf(" %c", &flag);
        if (tolower(flag) == 'b'){
            settingsSwitchHub ();
        }
        else{
            terminate();
        }
    }
}

void settingContributorList () {
    screenClear ();

    bannerCenBorder ("Educational purpose only", "Redistribution of project is not allowed",
                     "Created by the 1st year student IT KMITL 14", "POS Version 1.0");
    bannerBlankBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Lists of team members");
    bannerFullBorderSection ();
    bannerBlankBorderTextCen ("Kunanon   Srisuntiroj   @sagelga      59070022");
    bannerBlankBorderTextCen ("Thanawat  Laodkaew      @skydddoogg   59070071");
    bannerBlankBorderTextCen ("Noppanut  Ploywong      @noppanut15   59070082");
    bannerBlankBorderTextCen ("Vasanchai Prakobkij     @59070156     59070156");
    bannerBlankBorderTextCen ("Weerakorn Pongpum                     59070163");

    for ( int i = 2; i > 0; i-- )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Over 5000 lines of pure C language has been neatly crafted with love and passion <3");
    bannerBlankBorderTextCen ("See our GitHub Repository : https://github.com/sagelga/ComPro_Project");

    for ( int i = 18; i > 0; i-- )
        bannerBlankBorder ();

    bannerBlankBorderTextCen ("Redirecting you back in 10 seconds...");
    bannerFullBorder ();

    delay (10);
}

void settingCat () {
    int i = 0;
    char text1[300] = "", text2[300] = "", text3[300] = "", text4[300] = "";

    for ( int i = 0; i < 88; i++ ) {
        screenClear ();

        bannerFullBorder ();

        for (int k = 8;k>0;k--) {
            strcpy (text1, " ");
            strcpy (text2, " ");
            strcpy (text3, " ");
            strcpy (text4, " ");

            for ( int j = i; j > 0; j-- ) {
                strcat (text1, "_");
            }
            strcat (text1, "━━━━___━*━___━━___━___*___━_*___┓╭━━━━━━━━━━━━╮");
            bannerBlankBorderTextLeft (text1);

            for ( int j = i; j > 0; j-- ) {
                strcat (text2, "_");
            }
            strcat (text2, "___━━__*_━━___━━___━━*____━━___┗┓|::::::^----^|");
            bannerBlankBorderTextLeft (text2);

            for ( int j = i; j > 0; j-- ) {
                strcat (text3, "_");
            }
            strcat (text3, "___━━___━━___━*━___━━____━━*___━┗|:::::|｡◕‿‿◕｡|");
            bannerBlankBorderTextLeft (text3);

            for ( int j = i; j > 0; j-- ) {
                strcat (text4, "_");
            }
            strcat (text4, "___━━___*━__━━_*___━━___*━━___*━━╰O--O---O--O ╯");
            bannerBlankBorderTextLeft (text4);

            bannerBlankBorder ();
        }

        bannerFullBorder ();
        i++;
        delay (1);
    }
}

void settingUpdateStoreName (char *storeName) {
    strcpy (Setting.storeName, storeName);
    settingFileWrite ();    // Save to a Database file

}

void settingUpdateAddress (char *storeAddress) {
    strcpy (Setting.storeAddress, storeAddress);
    settingFileWrite ();    // Save to a Database file
}

void settingUpdatePriceToPoint (double priceToPoint) {
    Setting.priceToPoint = priceToPoint;
    settingFileWrite ();    // Save to a Database file
}

void settingUpdatePointToPrice (double pointToPrice) {
    Setting.pointToPrice = pointToPrice;
    settingFileWrite ();    // Save to a Database file
}


/*
 *                                             All hail the god..
 *  -----------------------------------------------------------------------------------------------------------------------
 *  |      _=_      ||      _=_      ||      _=_      ||      _=_      ||      _=_      ||      _=_      ||      _=_      |
 *  |    q(-_-)p    ||    q(-_-)p    ||    q(-_-)p    ||    q(-_-)p    ||    q(-_-)p    ||    q(-_-)p    ||    q(-_-)p    |
 *  |    '_) (_`    ||    '_) (_`    ||    '_) (_`    ||    '_) (_`    ||    '_) (_`    ||    '_) (_`    ||    '_) (_`    |
 *  |    /__/  \    ||    /__/  \    ||    /__/  \    ||    /__/  \    ||    /__/  \    ||    /__/  \    ||    /__/  \    |
 *  |  _(<_   / )_  ||  _(<_   / )_  ||  _(<_   / )_  ||  _(<_   / )_  ||  _(<_   / )_  ||  _(<_   / )_  ||  _(<_   / )_  |
 *  | (__\_\_|_/__) || (__\_\_|_/__) || (__\_\_|_/__) || (__\_\_|_/__) || (__\_\_|_/__) || (__\_\_|_/__) || (__\_\_|_/__) |
 *  |---------------||---------------||---------------||---------------||---------------||---------------||---------------|
 *  |     Hello     ||     Hello     ||     Hello     ||     Hello     ||     Hello     ||     Hello     ||     Hello     |
 *  |     Monday    ||    Tuesday    ||   Wednesday   ||    Thursday   ||     Friday    ||    Saturday   ||     Sunday    |
 *  -----------------------------------------------------------------------------------------------------------------------
 *                                         Program bug best enemy
 *                                 Please. No bug. No crash. No interrupt.
 *  -----------------------------------------------------------------------------------------------------------------------
 */