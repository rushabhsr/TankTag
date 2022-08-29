var text = 100;
var button = document.getElementById("reset");
var T1h = document.getElementById("Tank1health");
var T2h = document.getElementById("Tank2health");

var t1 = fref = firebase.database().ref().child("Tank1");
t1.on('value',function(tank1snap){
	Tank1health.innerText = tank1snap.val();
})
var t2 = fref = firebase.database().ref().child("Tank2");
t2.on('value',function(tank2snap){
	Tank2health.innerText = tank2snap.val();
})
//window.alert("Tank1 Health is "+text);
var interval;
var minutes = 2;
var seconds = 0;

	function countdown(element) {
        interval = setInterval(function() {
            var el = document.getElementById("timer");
            if(seconds == 0) {
                if(minutes == 0) {
                    alert(el.innerHTML = "countdown's over!");                    
                    clearInterval(interval);
                    return;
                } else {
                    minutes--;
                    seconds = 59;
                }
            }
            el.innerHTML = minutes + ':' + seconds;
            seconds--;
        }, 1000);
    }

function reset(){
	var val = text;
	var fref = firebase.database().ref();
	fref.child("Tank1").set(val);
	fref.child("Tank2").set(val);
	fref.child("Start").set("0");
	window.alert("Database is Reset");
	minutes = 2;
    seconds = 0;
    clearInterval(interval);
    interval = null;
    document.getElementById("timer").innerHTML = '2:00';
}
function start(){
	var fref = firebase.database().ref();
	fref.child("Start").set("1");
	if (!interval) {
        countdown('timer');
    }

}