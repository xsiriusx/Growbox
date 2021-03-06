/* ===================================================================== *
 *                                                                       *
 * Dynamic content                                                       *
 *                                                                       *
 * ===================================================================== *
 */


byte setpointtempday
// when this value comes from an EEPROM, load it in setup
                          // at the moment here is no setup function (To-Do)
void temperatura(uint8_t setpointdaytemp)
// *********************************************************************
{
  // check if this function is active (cursor stands on this line)
  if (line == LCDML.MENU_getCursorPos())
  {
    // make only an action when the cursor stands on this menu item
    //check Button
    if(LCDML.BT_checkAny())
    {
      if(LCDML.BT_checkEnter())
      {
        // this function checks returns the scroll disable status (0 = menu scrolling enabled, 1 = menu scrolling disabled)
        if(LCDML.MENU_getScrollDisableStatus() == 0)
        {
          // disable the menu scroll function to catch the cursor on this point
          // now it is possible to work with BT_checkUp and BT_checkDown in this function
          // this function can only be called in a menu, not in a menu function
          LCDML.MENU_disScroll();
        }
        else
        {
          // enable the normal menu scroll function
          LCDML.MENU_enScroll();
        }

        // do something
        // ...
      }

      // This check have only an effect when MENU_disScroll is set
      if(LCDML.BT_checkUp())
      {
        setpointtempday++;
      }

      // This check have only an effect when MENU_disScroll is set
      if(LCDML.BT_checkDown())
      {
        setpointtempday--;
      }


      if(LCDML.BT_checkLeft())
      {
        setpointtempday++;
      }
      if(LCDML.BT_checkRight())
      {
        setpointtempday--;
      }
    }
  }

  char buf[20];
  sprintf (buf, "dynValue: %d", teperatura);

  // use the line from function parameters
  lcd.setCursor(1, line);
  EEPROM.update(4);
  lcd.print(buf);

}
