function countMe(tag, obj)
{
    var elements = document.getElementsByTagName(tag);
    var classes = div.getElementsByClassName(obj.Class);
    var id = document.getElementById(obj.Id);
    var name = document.getElementsByName(obj.Name);
    if(id)
        id = "true";
    else
        id = "false";
    var output = "{all: " + elements.length;
    output += ", Class: " + classes.length;
    output += ", Id: "+ id;
    output += ", Name: " + name.length +"}"
    console.log(output)
}