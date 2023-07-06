function setTime() {
  let time =  new Date();

  const hour = time.getHours();
  const minute = time.getMinutes();
  const second = time.getSeconds();

  const hourHand = document.querySelector(".hours");
  const minutesHand = document.querySelector(".minutes");
  const secondsHand = document.querySelector(".seconds");

  const hourDeg = (hour / 12) * 360 + (minute / 60) * 30;
  const minuteDeg = (minute / 60) * 360 + (second / 60) * 6;
  const secondDeg = (second / 60) * 360;

    let trans = `translate(-50%, -100%)`;

    hourHand.style.transform = trans +  `rotate(${hourDeg}Deg) ` ;
    minutesHand.style.transform = trans + `rotate(${minuteDeg}Deg) ` ;
    secondsHand.style.transform = trans + `rotate(${secondDeg}Deg) ` ;
}

setInterval(setTime, 1000);
