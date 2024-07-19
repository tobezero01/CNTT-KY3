// coding implementation

/*function sendTo() {
    var arr = document.getElementsByTagName('input')
    var email = arr[0].value;
    var com = arr[1].value;
    var rating = arr[2].value;

    //var check = 0;
    /*kiem tra button
    var check1 = arr[5].checked;
    var check2 = arr[6].checked;
    var check3 = arr[7].checked;
    var gender = "";
    if (arr[3].checked) {
        gender = "male"
    } else {
        gender = "female";
    }
    if (check1||check2||check3) {
        return true;
    } else {
        alert("Least ome must be checked!");
        return;
    }
    */
   /* liem tra sdt 
   //var phone = arr[8].value;
   var p = /^\d{3}[-\s]?\d{3}[-\s]?\d{4}$/.test(phone);
   if (!p) alert("Phone is not true!");*/

    /*kiem tra rong 
    if (email == "" || com == "" || rating == "") {
        alert("Please fill all fields!");
        return;
    } 
    if (isNaN(rating)) { // is not a number
        alert("Rating must be a number!");
        return ;
    } 
    // kiem tra email
    var a = /^[^ ]+@[^ ]+\.[^ ]{2,3}$/.test(email)
    if(!a) {
        alert("It is not a valid email!");
        return ;
    } 
    
    */
//}
const check = document.querySelector('#submit');
check.addEventListener('click',sendTo);
function sendTo(){
    var email = document.getElementById('email').value;
    var comment = document.getElementById('com').value;
    var rating = document.getElementById('rate').value;

    if(email == '' || comment == '' || rating =='') {
        alert("Please fill all fields!");
        return;   
    }

    var a = /^[^ ]+@[^ ]+\.[^ ]{2,3}$/.test(email);
    if(!a) {
        alert("It is not a valid email!");
        return ;
    } 

    if(isNaN(rating)) {
        alert("Rating must be a number!");
        return ;
    }
    
    alert("Successfull!");
    //var sdt = /^\d{4}-\d{3}-\d{3}$/.test(comment);
   //if(!sdt) alert('sdt ko dugn dinh dang');
    
}

// end coding implementation