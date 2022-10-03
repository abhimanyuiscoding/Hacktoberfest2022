window.onload = function () {
    var seconds = 00;
    var tens = 00;
    var appendTens = document.getElementById("tens")
    var appendSeconds = document.getElementById("seconds");
    var buttonStart = document.getElementById('button-start');
    var buttonLap = document.getElementById('button-lap');
    var buttonStop = document.getElementById('button-stop');
    var buttonReset = document.getElementById('button-reset');
    var lapList = document.getElementById('laps');
    var lapCounter = 1;
    var Interval;

    buttonStart.onclick = function () {
        clearInterval(Interval);
        Interval = setInterval(startTimer, 10);
    }

    buttonLap.onclick = function () {
        lapList.innerHTML += '<li> <span class="lap-seconds">' + appendSeconds.innerHTML + '</span>:<span class="lap-tens">'+ appendTens.innerHTML + '</span> -- Lap ' + lapCounter + '</li>';
        lapCounter++;
        storeLaps();
    }

    buttonStop.onclick = function () {
        clearInterval(Interval);
    }

    buttonReset.onclick = function () {
        clearInterval(Interval);
        tens = "00";
        seconds = "00";
        appendTens.innerHTML = tens;
        appendSeconds.innerHTML = seconds;
        lapList.innerHTML = "";
        lapCounter = 1;
        storeLaps();
    }

    function startTimer() {
        tens++;

        if (tens < 9) {
            appendTens.innerHTML = "0" + tens;
        }

        if (tens > 9) {
            appendTens.innerHTML = tens;
        }

        if (tens > 99) {
            console.log("seconds");
            seconds++;
            appendSeconds.innerHTML = "0" + seconds;
            tens = 0;
            appendTens.innerHTML = "0" + 0;
        }

        if (seconds > 9) {
            appendSeconds.innerHTML = seconds;
        }
    }

    function storeLaps() {
        window.localStorage.myLaps = lapList.innerHTML;
    }

    function getLaps() {
        lapList.innerHTML = window.localStorage.myLaps;
    }
    getLaps();
}
