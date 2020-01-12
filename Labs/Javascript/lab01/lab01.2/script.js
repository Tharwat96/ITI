function returnIndex(str, letter)
{
    var indices = [];
    for(var i = str.indexOf(letter); i <= str.lastIndexOf(letter); i++)
    {
        if(str[i] === letter)
            indices.push(i);
    }
    for(var i = 0; i < indices.length; i++)
        console.log(indices[i] + " ");
}