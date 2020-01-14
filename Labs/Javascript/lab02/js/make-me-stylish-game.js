function makeMeStylish(tag, obj)
{
    var elements = document.getElementsByTagName(tag);
    for(var i = 0; i < elements.length; i++)
    {
        var element = elements[i];
        var style;
        for(var key in obj)
        {
            style += key + ":" + obj[key] + ";";
        }
        element.style = style;
    }

}