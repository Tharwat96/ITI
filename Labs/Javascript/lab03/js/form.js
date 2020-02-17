function validate(e)
{
    var errors="";
    var errorsList = document.getElementsByClassName("errors")[0];
    var errorMsg = document.getElementById("error-messages");
    var fields = e.toElement.form.elements;
    if(fields[0].value == "")   //name field
    {
        errors += "<li>- Name is required.</li>";
    }
    if(fields[1].value == "")   //email field
    {
        errors += "<li>- Email is required.</li>";
    }
    if(fields[2].value.length < 8)   //password field
    {
        errors += "<li>- Password must be 8 chars at least.</li>";
    }
    if(fields[3].checked === false && fields[4].checked === false)   //Gender radio buttons
    {
        errors += "<li>- Please select your gender.</li>";
    }
    var checked = 0;
    for(var i = 5; i < 10; i++)   //sports checkboxes check
    {
        if(fields[i].checked === true)
            checked++;
    }
    if(checked < 2)
        errors += "<li>- Please select at least two sports.</li>";

    if(fields[10].value == "")   //country select check
    {
        errors += "<li>- Please select your country.</li>";
    }
    
    console.log(e.toElement.form.elements)

    if(errors !== "")
    {
        e.preventDefault();
        errorMsg.innerHTML = errors;
        errorsList.style.display = "block"
    }
}

var submit = document.getElementById("saveForm");
submit.addEventListener("click", validate);