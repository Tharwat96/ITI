// var googleMapSrc = "http://maps.googleapis.com/maps/api/staticmap?center="+latlon+"&zoom=14&size=400x300&sensor=false";
var btn = document.querySelector("#get-loc");
var lat = document.querySelector("#lat")
var lon = document.querySelector('#lon')
var map = document.querySelector("#map");
var longitude,latitude;
btn.addEventListener('click',function(e){
    navigator.geolocation.getCurrentPosition(function(pos){
        latitude=pos.coords.latitude;
        longitude=pos.coords.longitude;

    })
    lat.innerHTML=latitude;
    lon.innerHTML=longitude;
    map.src=`https://www.mapquestapi.com/staticmap/v5/map?locations=${latitude},${longitude}&size=@2x&key=rCn7zRIkdYBAcG7FSwpAhtMBc9CSkrla`
})

