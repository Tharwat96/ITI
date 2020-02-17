function calcCoins(n)
{
    var dollars, quarters, dimes, nickels, cents, counter=0;
    nFixed = n.toFixed(2);
    while(counter <= 4)
    {    
        switch(counter)
        {
            case 0:
                dollars = parseInt(n);
                n = n - dollars;
                counter++;
                break;
            case 1:     //calculating quarters if any
                if(n != null && n > 0)
                {
                    n = n*100;
                    if(n >= 25)
                    {
                        quarters = Math.floor(n/25);
                        n = n - quarters*25;
                        counter++;
                    }
                    else
                    {
                        quarters = 0;
                        counter++;
                    }

                } 
                break;
            //====
            case 2:     //calculating dimes if any
                if(n != null && n > 0)
                {
                    if(n >= 10)
                    {
                        dimes = Math.floor(n/10);
                        n = n - dimes*10;
                        counter++;
                    }
                    else
                    {
                        dimes = 0;
                        counter++;
                    }
                }
                break;
            //====
            case 3:     //calculating nickels if any
                if(n != null && n > 0)
                {
                    if(n >= 5)
                    {
                        nickels = Math.floor(n/5);
                        n = n - nickels*5;
                        counter++;
                    }
                    else
                    {
                        nickels = 0;
                        counter++;
                    }
                }
                break;
            //=====
            case 4:     //calculating cents if any
                if(n != null && n > 0)
                {
                    if(n >= 1)
                    {
                        cents = Math.floor(n);
                        n = n - cents;
                        counter++;
                    }
                    else
                    {
                        cents = 0;
                        counter++;
                    }
                }
                break;
            default: 
                break;
        }
    }
    if(counter === 5)
    {
        console.log("You have " + dollars + " dollar, "+ quarters + " quarter, " + dimes + " dime, " + nickels + " nickel and " + cents + " cent.")
    }
    else
        console.log("Something went wrong!");
}