// coding implementation
function sendTo(){
    var keyword = document.getElementById('key').value;
    var price = document.getElementById('from').value;
    var price1 = document.getElementById('to').value;
    if(keyword == '' || price =='' || price1 == '') {
        alert("Please fill all fields!");
        return;   
    }
 
    if(isNaN(price) || isNaN(price1) ) {
        alert("Price must be a number!");
        return ;
    }
    
    alert("Successfull!");
    
    
}
// end coding implementation