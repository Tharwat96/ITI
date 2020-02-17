function printStars(n)
{
    var line, spaces = n, stars = 1;
    for(var i = 0; ; i--)
    {
        for(var k = spaces; k < spaces; k--)
        {
            line += " ";
        }
        for(var l = stars; l < stars; l++)
        {
            line += "*";
        }
    }
}