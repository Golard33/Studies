"use strict";
let ws;
let codebarre = "no barcode";
function connect() {
    if (ws !== undefined && ws.readyState !== WebSocket.CLOSED) {
        return;
    }
    ws = new WebSocket("ws://localhost:2006/PalacioRobin/WebSocket");
    ws.onopen = function () {
        console.log("connected");
    };
    ws.onmessage = (event) => {
        let nutriscore = window.document.getElementById('nutriscore');
        console.log(event.data);
        if (nutriscore !== null)
            nutriscore.textContent = event.data;
        console.log("onmessage : " + event.data);
    };
    ws.onclose = function () {
        console.log("connection closed");
    };
}
function send(codebarre) {
    ws.send(codebarre);
}
function closeSocket() {
    ws.close();
}
connect();
let _DOM_ready = null;
Object.defineProperty(window, "DOM_ready", {
    value: new Promise(launched_function_when_DOM_ready => {
        _DOM_ready = launched_function_when_DOM_ready;
    }), enumerable: false, configurable: false, writable: false
});
window.document.onreadystatechange = _DOM_ready;
window.DOM_ready.then(() => {
    /* Webcam shooting */
    const _my_video = window.document.getElementById('my_video');
    _my_video.addEventListener('canplay', () => {
        window.console.log("The video is playing...");
        window.console.log("_my_video.videoHeight: " + _my_video.videoHeight + " _my_video.videoWidth: " + _my_video.videoWidth);
    });
    const _working_canvas = window.document.createElement('canvas');
    let constraints = { audio: false, video: true };
    if (window.navigator.mediaDevices.getSupportedConstraints().hasOwnProperty('facingMode')) {
        constraints = { audio: false, video: { facingMode: 'user' } }; // Selfie mode...
    }
    const _video_management = () => {
        if (_my_video.srcObject !== null) {
            // Video is running, take photography:
            if (_my_video.srcObject.getVideoTracks()[0].readyState === 'live') {
                /*  (window as any).Snapshot.then((sound: any) => {
                      sound.play();
                  });*/
                // Before stopping the camera, one records the last frame:
                _working_canvas.setAttribute('width', _my_video.videoWidth.toString());
                _working_canvas.setAttribute('height', _my_video.videoHeight.toString());
                _working_canvas.getContext('2d').drawImage(_my_video, 0, 0, _my_video.videoWidth, _my_video.videoHeight);
                const _selfie = new Image();
                _selfie.onload = () => {
                    // This immediately stops the webcam (Firefox keeps the last frame on screen while Chrome generates a black screen):
                    _my_video.srcObject.getVideoTracks()[0].stop();
                    // The stream is no longer active:
                    window.console.assert(_my_video.srcObject.active === false);
                    window.console.assert(_my_video.srcObject.getVideoTracks()[0].readyState === 'ended');
                    // The stream is detached from the '<video>' tag:
                    _my_video.srcObject = null; // For next shoot...
                    _my_video.setAttribute('poster', _selfie.src);
                };
                _selfie.src = _working_canvas.toDataURL("image/png"); // From canvas to image...
                Quagga.decodeSingle({
                    decoder: {
                        readers: ["ean_reader"] // List of active readers
                    },
                    locate: true,
                    src: _working_canvas.toDataURL("image/png") // or 'data:image/jpg;base64,' + data
                }, function (result) {
                    let barcode = window.document.getElementById('barcode');
                    if (result === null || result === void 0 ? void 0 : result.codeResult) {
                        console.log("result", result.codeResult.code);
                        codebarre = result.codeResult.code;
                        barcode.textContent = codebarre;
                        send(codebarre);
                    }
                    else {
                        barcode.textContent = "bar code not detected";
                        console.log("not detected");
                    }
                });
            }
            else
                window.alert("_my_video.srcObject.getVideoTracks()[0].readyState === 'ended'");
        }
        else { // New stream is required (with permission?)
            // Firefox asks for permission again...
            window.navigator.mediaDevices.getUserMedia(constraints).then((stream) => {
                // Safari issue here:
                // https://help.milkshake.tv/hc/en-us/articles/115005464689-Videos-not-playing-when-using-Safari-11-web-browser
                _my_video.srcObject = stream; // Assign the webcam to the "my_video" HTML element
                _my_video.play(); // Start playing video...
            }).catch((error) => {
                window.alert("window.navigator.mediaDevices.getUserMedia: " + error.message);
            });
        }
    };
    if (window.PointerEvent) // May not work for some browsers...
        _my_video.onpointerup = _video_management;
    else // Older Safari versions do not support 'window.PointerEvent': https://caniuse.com/#feat=pointer
        _my_video.addEventListener('mouseup', _video_management, true);
});
