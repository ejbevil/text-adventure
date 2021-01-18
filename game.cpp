/**********************************************************
Erica Bevilacqua
Text Adventure Game
**********************************************************/

#include <iostream>
#include <fstream>
#include "game.hpp"
#include "actionspace.hpp"
#include "creaturespace.hpp"
#include "winlosespace.hpp"


/**********************************************************
                     constructor
parameters: none
description: Initializes head & currSpace ptrs,  airSupply,
 and event flags & calls function to generate linked Spaces
returns: n/a
**********************************************************/
Game::Game()
{
    head = currSpace = nullptr;
    airSupply = 50;

    doorUnlocked = false;
    portholeOpened = false;

    // Allocate, initialize, & link all spaces
    createWorld();
}


/**********************************************************
                     createWorld()
parameters: none
description: Allocates, initializes, & links all Space
 objects.
returns: nothing
**********************************************************/
void Game::createWorld()
{
    // Allocate & link spaces                           //[0][0]
    currSpace = head = new WinLoseSpace("upperLeftOcean",
    "\nYou are not far below the ocean's surface. Above you, you can still"
    "\nmake out the silhouette of your boat. To the east is the hulking"
    "\nmass of Calypso's Curse. The ship appears to have been torn in two,"
    "\nthe entire stern half lost to the depths and the main deck now fully"
    "\nexposed to the sea. Below you is deeper, darker ocean, and to"
    "\nyour west, darker still.\n\n",
    "\n< Select: >"
    "\n[1] to return to the boat"
    "\n[2] to keep exploring\n");

    // Create & link to next                            //[0][1]
    currSpace->setRight(new ActionSpace("daggerRoom",
    "\nThis is the westernmost main deck room. The passage of time and"
    "\nexposure to the open sea has allowed a maze of coral to grow where"
    "\nthe west wall once stood. To the east is an open doorway to the"
    "\nnext room. In the corner you spy what appears to be the remains of"
    "\none of the ship's former occupants, now nothing but bones and an "
    "\neyepatch.\n\n",
    "\nThis is the westernmost main deck room. The passage of time and"
    "\nexposure to the open sea has allowed a maze of coral to grow where"
    "\nthe west wall once stood. To the east is an open doorway to the"
    "\nnext room. In the corner lies the pirate's skeleton, now contorted"
    "\nfrom your cruel jostling.\n\n",
    "\nAs you curiously poke at the former pirate, the DAGGER he clutched in"
    "\nhis bony hands for eons slips from his grasp. With a twinge of guilt,"
    "\nyou thrust it in your bag. It may serve as protection against any"
    "\nnumber of creatures down here.\n\n",
    "\n< Select: >"
    "\n[1] to desecrate the skeleton"
    "\n[2] to let it rest in its watery tomb\n"));
    // bottom ptr will be set once last Space allocated
    // Move to next space & link back to previous
    Space* temp = currSpace;
    currSpace = currSpace->getRight();
    currSpace->setLeft(temp);

    // Create & link to next                            //[0][2]
    currSpace->setRight(new CreatureSpace("emptyUpperRoom",
    "\nThis appears to be a central room on the main deck. You spy a"
    "\nbarnacle-encrusted cannon and a pile of cannonballs but they won't"
    "\nbe of much use down here. To the east and west are more upper-"
    "\nlevel rooms with passable doorways.\n\n",
    "stingray"));
    // Move to next space & link back to previous
    temp = currSpace;
    currSpace = currSpace->getRight();
    currSpace->setLeft(temp);

    // Create & link to next                            //[0][3]
    currSpace->setRight(new ActionSpace("keyRoom",
    "\nYou are in the easternmost room of the main deck, closest to the"
    "\nbowsprit. To the west is more of the main deck, and to the east, a"
    "\nsmall hole in the ship's side allows passage back out into the open"
    "\nocean. Just beneath the hole is purple and orange octopus, perched"
    "\nstoically atop a mound of debris.\n\n",
    "\nYou are in the easternmost main deck room, closest to the bowsprit."
    "\nbowsprit. To the west is more of the main deck, and to the east, a"
    "\nsmall hole in the ship's side allows passage back out into the open"
    "\nocean. There is no sign of the octopus.\n\n",
    "\nThe octopus, apparently not feeling playful, darts away, startling"
    "\nyou. In the spot he previously occupied, you detect a flash of gold."
    "\nYou scoop up the KEY and throw it into your bag.\n\n",
    "\n< Select: >"
    "\n[1] to harass the octopus"
    "\n[2] if you have better things to do\n"));
    // Move to next space & link back to previous
    temp = currSpace;
    currSpace = currSpace->getRight();
    currSpace->setLeft(temp);

    // Create & link to next                            //[0][4]
    currSpace->setRight(new CreatureSpace("upperRightOcean",
    "\nYou are outside of the ship, to the east, and nearer to the ocean's"
    "\nsurface. To your west is the ship's bow; a hole in its side allows"
    "\naccess to the main deck. Below you is more ocean bordering the"
    "\nvessel. To the east is vast, endless sea.\n\n",
    "shark"));
    // Move to next space & link back to previous
    temp = currSpace;
    currSpace = currSpace->getRight();
    currSpace->setLeft(temp);

    // Create & link to next                            //[1][4]
    currSpace->setBottom(new ActionSpace("portholeOcean",
    "\nYou are in deeper ocean, outside of the ship's hull. Above"
    "\nyou is more ocean and the bow of the ship; below is sea floor."
    "\nThere is no way into the vessel here, but you see a porthole"
    "\nencircled in rusted iron.\n\n",
    "\nYou are in deeper ocean, outside of the ship's hull. Above"
    "\nyou is more ocean and the bow of the ship; below is sea floor."
    "\nThere is now a narrow void in the ship's side from where you"
    "\ndamaged the historical craft.\n\n",
    "\nYou place your flippered feet onto the ship's side and jerk"
    "\nthe porthole's iron trim with all of your might. To your amazement,"
    "\nnot only does the porthole come free but along with it, a sizable"
    "\nportion of water-logged wood, creating a hole in the ship's side"
    "\nyou think you can now squeeze through.\n\n",
    "\n< Select: >"
    "\n[1] to yank on the porthole"
    "\n[2] to leave the structure intact\n"));
    // Move to next space & link back to previous
    temp = currSpace;
    currSpace = currSpace->getBottom();
    currSpace->setTop(temp);

    // Create & link to next                            //[1][3]
    currSpace->setLeft(new ActionSpace("captainsQuarters",
    "\nYou have made it to the previously inaccessible Captain's quarters."
    "\nTo the east is the narrow hole you created which leads out into the"
    "\nsea. Against the door to the west, you spy the reason the door"
    "\nwouldn't budge: the Captain himself, or what remains of him, draped"
    "\nover a heavy wooden chest.\n\n",
    "\nYou have made it to the previously inaccessible Captain's quarters."
    "\nTo the east is the narrow hole you created which leads out into the sea"
    "\nsea. With the Captain slumped over in the corner and your treasure"
    "\nin tow, the door to the west now lies unobstructed.\n\n",
    "\nIn a frenzy, you shove the Captain's skeleton off of the chest and"
    "\neagerly thrust open its unlocked lid. Piles of gold coins and bars"
    "\ngleam back at you! You stare mesmerized for a moment, then slam the"
    "\nlid shut and grab hold of the heavy chest."
    "\nSuccess!!"
    "\nIn your frantic rush, however, you absentmindedly leave behind your"
    "\ndiver's bag and all of its contents!\n\n",
    "\n< Select: >"
    "\n[1] to greedily grab the treasure chest"
    "\n[2] leave it for the Captain\n"));
    // Move to next space & link back to previous
    temp = currSpace;
    currSpace = currSpace->getLeft();
    currSpace->setRight(temp);

    // Create & link to next                            //[1][2]
    currSpace->setLeft(new ActionSpace("lockedDoorRoom",
    "\nYou are in the central room on the lower deck. To your west is the"
    "\na passable doorway to another lower deck room. To your east, a"
    "\nsolid wall with an ornately carved door, fastened by a heavy iron"
    "\nlock.\n\n",
    "\nYou are in the central room on the lower deck. To your west is the"
    "\na passable doorway to another lower deck room. To your east, the"
    "\nwall with the ornately carved door.\n\n",
    "\nThe key slides in easily, and with a click, the lock springs open."
    "\nYou push, pull, bang, and kick the door, but it stays fast.\n\n",
    "\n< Select: >"
    "\n[1] to try opening the door"
    "\n[2] leave it sealed\n"));
    // Move to next space & link back to previous
    temp = currSpace;
    currSpace = currSpace->getLeft();
    currSpace->setRight(temp);

    // Create & link to next                            //[1][1]
    currSpace->setLeft(new ActionSpace("chestRoom",
    "\nThis is a lower deck room, open to the ocean to the west."
    "\nTo the east is a doorway to another lower deck room."
    "\nAgainst the wall you spot a massive wooden chest, crusted"
    "\nwith barnacles and coral.\n\n",
    "\nThis is the lower deck room, open to the ocean to the west."
    "\nTo the east is a doorway to another lower deck room."
    "\nAgainst the wall still sits the wooden chest with half a key lodged"
    "\nin its lock, taunting you.\n\n",
    "\nYou eagerly shove the key into the chest's lock and frantically turn"
    "\nit this way and that. It refuses to budge you, so you give it one"
    "\nfinal twist with both hands."
    "\nSNAP!! The key breaks in two!\n\n",
    "\n< Select: >"
    "\n[1] to attempt to open the chest"
    "\n[2] let its secrets stay hidden\n"));
    // Move to next space & link back to previous
    temp = currSpace;
    currSpace = currSpace->getLeft();
    currSpace->setRight(temp);

    // Create & link to next                            //[1][0]
    currSpace->setLeft(new CreatureSpace("lowerLeftOcean",
    "\nYou are enveloped by ocean to the west of the ship. To the east is"
    "\nthe lower deck of the vessel, conveniently open and vulnerable."
    "\nBelow you is the sandy ocean floor and further west, vast, endless"
    "\nsea.\n\n",
    "shark"));
    // Move to next space & link back to previous
    temp = currSpace;
    currSpace = currSpace->getLeft();
    currSpace->setRight(temp);
    // Link last & first space
    currSpace->setTop(head);
    head->setBottom(currSpace);

    // Reset currSpace so game begins at head
    currSpace = head;
    temp = nullptr;

    /* Spaces List
     "upperLeftOcean"
     "daggerRoom"
     "emptyUpperRoom"
     "keyRoom"
     "upperRightOcean"
     "portholeOcean"
     "captainsQuarters"
     "lockedDoorRoom"
     "chestRoom"
     "lowerLeftOcean"
     */
}


/**********************************************************
                         move()
parameters: none
description: Gets move direction from user & validates input.
 Attempts move & if valid, updates currSpace ptr & decrements
 airSupply. If not valid, loops.
returns: nothing
**********************************************************/
void Game::move()
{
    bool moveMade = false;
    do
    {
        // Prompt
        std::cout << "< Press number for desired direction: >\n"
                     "    [1]\n"
                     " [4]   [2]\n"
                     "    [3]\n";
        // Get & validate input; convert back to enum Direction type
        int moveDir = returnValidIntInRange(1, 4);
        auto dirChosen = static_cast<Direction>(moveDir);

        // If valid move, move to desired space & decrement air supply
        switch (dirChosen)
        {
            case UP:
                if (validMove(currSpace->getTop()))
                {
                    currSpace = currSpace->getTop();
                    moveMade = true;
                    airSupply--;
                }
                break;
            case RIGHT:
                if (validMove(currSpace->getRight()))
                {
                    currSpace = currSpace->getRight();
                    moveMade = true;
                    airSupply--;
                }
                break;
            case DOWN:
                if (validMove(currSpace->getBottom()))
                {
                    currSpace = currSpace->getBottom();
                    moveMade = true;
                    airSupply--;
                }
                break;
            case LEFT:
                if (validMove(currSpace->getLeft()))
                {
                    currSpace = currSpace->getLeft();
                    moveMade = true;
                    airSupply--;
                }
                break;
        }

    // Loop until valid move selected or air manually set to 0
    } while (!moveMade && airSupply != 0);
}


/**********************************************************
                     validMove()
parameters: pointer to space user is attempting to move to
 (Space*)
description: Checks if chosen move direction valid, either
 due to nullptr link or special conditions. If not valid,
 prints error message.
returns: true if move valid; false if not valid (bool)
**********************************************************/
bool Game::validMove(Space* nextSp)
{
    // Keep track of number of attempts at escaping Capt's Quarters
    static int attemptCount = 0;

    // Nonexistent space invalid moves
    bool validMove = true;
    if (!nextSp)
    {
        validMove = false;
        std::cout << "Try as you might, you can't move that direction.\n\n";
    }

    // Item/event-dependent invalid moves
    else if (currSpace->getType() == "lockedDoorRoom" &&
             nextSp->getType() == "captainsQuarters" &&
             !doorUnlocked)
    {
        validMove = false;
        std::cout << "You can't go in: The ornately carved door is"
                     " fastened shut\nby a large iron lock.\n\n";
    }
    else if (currSpace->getType() == "lockedDoorRoom" &&
             nextSp->getType() == "captainsQuarters" &&
             doorUnlocked && !inv.searchInInventory("treasure"))
    {
        validMove = false;
        std::cout << "The substantial lock hangs open but no amount"
                     " of shoving\nor pulling will budge the door.\n\n";
    }
    else if (currSpace->getType() == "portholeOcean" &&
             nextSp->getType() == "captainsQuarters" &&
             !portholeOpened)
    {
        validMove = false;
        std::cout << "The rusty porthole is just slightly too small"
                " for you\nto wedge yourself into.\n\n";
    }
    else if (currSpace->getType() == "captainsQuarters" &&
             nextSp->getType() == "portholeOcean" &&
             inv.searchInInventory("treasure"))
    {
        // Increment escape attempt count
        attemptCount++;
        validMove = false;
        std::cout << "Even with the hole enlarged from prying out"
                     " the porthole,\nyou can't fit through carrying"
                     " the large chest, but you can't\nbring yourself"
                     " to drop it. You swim in circles, exhausting"
                     "\nyour air supply...\n\n";
        // If 3 attempts, force air to 0, causing death
        //    *avoids infinite prompts for movement choice
        if (attemptCount > 2 )
        {
            airSupply = 0;
        }
    }
    else if (currSpace->getType() == "captainsQuarters" &&
             nextSp->getType() == "lockedDoorRoom" &&
             !doorUnlocked)
    {
        validMove = false;
        std::cout << "As you repeatedly push on the door, you feel it"
                " give, but it stays\nstubbornly sealed. It must still"
                " be locked from the outside!\n\n";
    }

    return validMove;
}


/**********************************************************
                         act()
parameters: none
description: For non-action spaces (CreatureSpace), prints
 message. For win-lose space, calls its doAction() method.
 For all other action spaces, calls its doAction() method
 and then calls processAction() to perform appropriate
 modifications to inventory & event flags.
returns: nothing
**********************************************************/
void Game::act()
{
    // Non-action rooms
    if (currSpace->getType() == "emptyUpperRoom" ||
        currSpace->getType() == "upperRightOcean" ||
        currSpace->getType() == "lowerLeftOcean")
    {
        std::cout << "\nThere's nothing you can accomplish here"
                     " -- why not explore further?\n\n";
    }

    // Win-Lose space
    else if (currSpace->getType() == "upperLeftOcean")
    {
        // Attempt action
        currSpace->doAction(inv.searchInInventory("treasure"));
        // If action taken, will be processed by end conditions check
    }

    // Action Spaces
    else
    {
        // Attempt action
        bool hasActed = currSpace->doAction(inv.searchInInventory("key"));

        // If action taken, decrement air supply & perform
        //   follow-up changes to events/inventory
        if (hasActed)
        {
            airSupply--;
            processAction();
        }
    }
}


/**********************************************************
                      processAction()
parameters: none
description: Adds/removes inventory items or toggles event
 flags after action in a particular space has been taken.
returns: nothing
**********************************************************/
void Game::processAction()
{
    if (currSpace->getType() == "daggerRoom")
    {
        inv.addToInventory("dagger");
    }
    else if (currSpace->getType() == "keyRoom")
    {
        inv.addToInventory("key");
    }
    else if (currSpace->getType() == "chestRoom")
    {
        inv.removeFromInventory("key");
    }
    else if (currSpace->getType() == "lockedDoorRoom")
    {
        doorUnlocked = true;
    }
    else if (currSpace->getType() == "portholeOcean")
    {
        portholeOpened = true;
    }
    else if (currSpace->getType() == "captainsQuarters")
    {
        inv.clearInventory();
        inv.addToInventory("treasure");
    }
}



/**********************************************************
                       readMap()
parameters: none
description: Displays ASCII map of environment, read from
 file, to screen.
returns: nothing
**********************************************************/
void Game::readMap()
{
    std::ifstream ifs("map.txt");
    if (ifs)
    {
        std::string line;
        while (getline(ifs, line)) {
            std::cout << line << "\n";
        }
        std::cout << "\n";
        ifs.close();
    }
    else
    {
        std::cout << "Cannot display map.\n\n";
    }
}


/**********************************************************
                  checkEndConditions()
parameters: none
description: Checks end conditions and returns t/f. Game
 ends if run out of air or return to boat (w/ or w/o
 treasure). Creature attack also ends game, but not handled
 by this function.
returns: true if game should end, false otherwise (bool)
**********************************************************/
bool Game::checkEndConditions()
{
    bool endGame = false;

    // Run out of air = LOSE
    if (airSupply <= 0)
    {
        endGame = true;
        std::cout << "\n\nYour oxygen tank has run out!!\n"
                     "You hold your last remaining breath as long as you"
                     " can but your lungs, spasming, finally concede.\n"
                     "Water rushes in and the world fades to black...\n\n";
    }

    // If return to boat
    else if (currSpace->getType() ==  "upperLeftOcean" &&
        currSpace->getActionTaken() )
    {
        // empty handed = LOSE
        if (!inv.searchInInventory("treasure"))
        {
            endGame = true;
            std::cout << "You return to the boat alive, but overwhelmed"
                         " with\nsoul-crushing defeat.\n\n";
        }
        // with treasure = WIN
        else if (inv.searchInInventory("treasure"))
        {
            endGame = true;
            std::cout << " ** YOU WIN!! **"
                         "\nYou hoist the heavy chest onto the boat and begin"
                         "the journey\nback to shore...\n\n";
        }
    }

    // Creature attack also ends game, but occurs immediately

    // Using key on non-treasure chest makes game un-winnable, but must
    //    run out of air to end

    return endGame;
}


/**********************************************************
                       runGame()
parameters: none
description: Runs full game, presenting title & intro text,
 then looping menu and execution of user selection, until
 end conditions met or use quits.
returns: nothing
**********************************************************/
void Game::runGame()
{
    // Display title & intro text
    // Title graphics via http://www.patorjk.com/software/taag/
    std::ifstream ifs("intro.txt");
    if (ifs)
    {
        std::string line;
        while (getline(ifs, line))
        {
            std::cout << line << "\n";
        }
        std::cout << "\n";
        ifs.close();
    }
    else
    {
        std::cout << "Cannot locate title and intro text.\n\n";
    }

    // Display map 1x
    readMap();

    bool endGame = false;
    do
    {
        // Display space description
        std::cout << currSpace->getDescrip();

        // Check for creature attack
        if (currSpace->creatureAttack(inv.searchInInventory("dagger")))
        {
            return;
        }

        // Loop menu & execution of choice until user has moved
        bool hasMoved = false;
        do
        {
            // Main Menu
            std::cout <<
                      "                                 ((Air: " << airSupply
                                                                 << " DL))\n"
                      "*..............................................*\n"
                      " Press:\n"
                      " [1] to Move             [4] to View Inventory\n"
                      " [2] to Perform Action   [5] to QUIT\n"
                      " [3] to View Map\n"
                      "*..............................................*\n\n";

            // Validate & execute Choice
            int menuChoice = returnValidIntInRange(1, 5);
            switch (menuChoice)
            {
                case 1:
                    move();
                    hasMoved = true;
                    break;
                case 2:
                    act();
                    break;
                case 3:
                    readMap();
                    break;
                case 4:
                    inv.listInventory();
                    break;
                case 5:
                    return;
            }

            // Check end conditions
            endGame = checkEndConditions();
            if (endGame)
            {
                return;
            }

        } while (!hasMoved);

    } while (!endGame);
}


/**********************************************************
                       destructor
parameters: n/a
description: Deallocates Space objects
returns: n/a
**********************************************************/
Game::~Game()
{
    Space* ptr = head;
    Space* ptr2 = head->getBottom();

    // Move through upper level rooms & delete Space objects
    while (ptr)
    {
        Space* garbage = ptr;
        ptr = ptr->getRight();
        delete garbage;
    }
    // Move through lower level rooms & delete Space objects
    while (ptr2)
    {
        Space* garbage = ptr2;
        ptr2 = ptr2->getRight();
        delete garbage;
    }
    ptr = ptr2 = head = currSpace = nullptr;
}



