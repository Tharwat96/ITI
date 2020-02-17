var counter = 1, editFlag = 0, rowNum = 2;
class Contact {
    constructor(name, email, phone) {
        this.id = counter;
        this.name = name;
        this.email = email;
        this.phone = phone;
    }
}

class ContactList {
    constructor() {
        this.contacts = new Array;
    }

    addContact(contact) {
        this.contacts.push(contact);
        counter++;
    }

    removeContact(id) {
        this.contacts.splice(this.contacts[id], 1);
    }

    editContact(id, updatedContact) {
        this.contacts[id-1] = updatedContact;    
    }

    getContact(id) {
        for(let i = 0; i < this.contacts.length; i++)
        {
            if(id == this.contacts[i].id)
                return this.contacts[i];
        }
    }

    getAllContacts() {
        return this.contacts;
    }

}
var list = new ContactList;
///////////////Submit button///////////////////////////
var submitBtn = document.getElementById("submit");
var submitEvent = function (e) {
    e.preventDefault();
    var inputs = document.getElementsByTagName("input");
    if (inputs[0].value === "" || inputs[1].value === "" || inputs[2].value === "")
        alert("All fields are required!");
    else if(editFlag !== 0){
        console.log(editFlag);
        tempContact = new Contact(inputs[0].value, inputs[1].value, inputs[2].value);
        list.editContact(editFlag, tempContact);
        for (let i = 0; i < 3; i++)
            inputs[i].value = "";
        editFlag = 0;
        addToList(tempContact);
    }
    else {
        tempContact = new Contact(inputs[0].value, inputs[1].value, inputs[2].value);
        list.addContact(tempContact);
        for (let i = 0; i < 3; i++)
            inputs[i].value = "";
        addToList(tempContact);
    }

}
submitBtn.addEventListener("click", submitEvent);
//////////////////row actions//////////////////////
function addToList(contact){
    var table = document.getElementsByTagName("table")[0];
    var deleteBtn = document.createElement("BUTTON");
    deleteBtn.innerHTML = "Delete";
    deleteBtn.value = contact.id;
    var editBtn = document.createElement("BUTTON");
    editBtn.innerHTML = "Edit";
    editBtn.value = contact.id;
    row = table.insertRow(rowNum);
    cell1 = row.insertCell(0);
    cell2 = row.insertCell(1);
    cell3 = row.insertCell(2);
    cell4 = row.insertCell(3);
    cell1.innerHTML = contact.name;
    cell2.innerHTML = contact.email;
    cell3.innerHTML = contact.phone;
    cell4.appendChild(editBtn);
    cell4.appendChild(deleteBtn);
    editBtn.addEventListener("click", editRow);
    deleteBtn.addEventListener("click", deleteRow);
    rowNum++;
}


function editRow(e){
    var inputs = document.getElementsByTagName("input");
    var id = e.target.value;    
    var contact = list.getContact(id);    
    inputs[0].value = contact.name;
    inputs[1].value = contact.email;
    inputs[2].value = contact.phone;
    editFlag = id;
    var row = e.target.parentNode.parentNode;
    row.parentNode.removeChild(row);
    rowNum--;
}

function deleteRow(e){
    var row = e.target.parentNode.parentNode;
    row.parentNode.removeChild(row);
    list.removeContact(e.target.value);
    rowNum--;
}
