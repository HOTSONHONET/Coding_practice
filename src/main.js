let startCount = 0;

const btnIds = [
    // For easy
    "easy_minus",
    "easy_cnt",
    "easy_plus",
    // For medium
    "medium_minus",
    "medium_cnt",
    "medium_plus",
    // For hard
    "hard_minus",
    "hard_cnt",
    "hard_plus",
]

// function createVariables(){
//     var tmpEvents = {};
//     for(let id of btnIds){
//         let level, operation = id.split("_");
//         let tmpId = level + "_cnt";
//         if(operation == "minus"){           
//             tmpEvents[id] = document.getElementById(id).addEventListener("click",
//                 function minusBtn() {
//                     let element = document.getElementById(tmpId);
//                     if (parseInt(element.textContent) > 0){
//                         let tmpCnt = parseInt(element.textContent) - 1;
//                         element.textContent = tmpCnt.toString();
//                     }
//                 }
        
//             );       

//         }
//         else if(operation == "plus")
//         {
//             tmpEvents[id] = document.getElementById(id).addEventListener("click",
//                 function plusBtn() {
//                     let element = document.getElementById(tmpId);
//                     let tmpCnt = parseInt(element.textContent) + 1;
//                     element.textContent = tmpCnt.toString();
//                 }
        
//             ); 
//         }
//     }
//     console.log(tmpEvents);
//     return tmpEvents;
// }


let start = document.getElementById("start").addEventListener("click",
    function enableAllCards() {
        startCount++;
        if (startCount % 2 == 1){
            for (let i = 0; i < btnIds.length; i++) {
            
                var element = document.getElementById(btnIds[i]);

                element.className = element.className.split(" ").slice(0, -1).join(" ");
                if(element.id.toString().split("_")[1] == "cnt"){
                    element.textContent = "0";
                }
            }

            // Adding functionality

            // plus
            let easyPlus = document.getElementById("easy_plus").addEventListener("click",
                function plusBtn() {
                    let element = document.getElementById("easy_cnt");
                    let tmpCnt = parseInt(element.textContent) + 1;
                    element.textContent = tmpCnt.toString();
                }
            
            );
            let mediumPlus = document.getElementById("medium_plus").addEventListener("click",
                function plusBtn() {
                    let element = document.getElementById("medium_cnt");
                    let tmpCnt = parseInt(element.textContent) + 1;
                    element.textContent = tmpCnt.toString();
                }
        
            );

            let hardPlus = document.getElementById("hard_plus").addEventListener("click",
                function plusBtn() {
                    let element = document.getElementById("hard_cnt");
                    let tmpCnt = parseInt(element.textContent) + 1;
                    element.textContent = tmpCnt.toString();
                }
        
            );

            // minus
            let easyMinus = document.getElementById("easy_minus").addEventListener("click",
                function minusBtn() {
                    let element = document.getElementById("easy_cnt");
                    if (parseInt(element.textContent) > 0){
                        let tmpCnt = parseInt(element.textContent) - 1;
                        element.textContent = tmpCnt.toString();
                    }
                }
            
            );
            let mediumMinus = document.getElementById("medium_minus").addEventListener("click",
                function minusBtn() {
                    let element = document.getElementById("medium_cnt");
                    if (parseInt(element.textContent) > 0){
                        let tmpCnt = parseInt(element.textContent) - 1;
                        element.textContent = tmpCnt.toString();
                    }
                }
            
            );
            let hardMinus = document.getElementById("hard_minus").addEventListener("click",
                function minusBtn() {
                    let element = document.getElementById("hard_cnt");
                    if (parseInt(element.textContent) > 0){
                        let tmpCnt = parseInt(element.textContent) - 1;
                        element.textContent = tmpCnt.toString();
                    }
                }
            
            );       


        }
        else{
            for (let i = 0; i < btnIds.length; i++) {
            
                var element = document.getElementById(btnIds[i]);
                const classname = element.className.split(" ")
                classname.push("disabled");
                element.className = classname.join(" ");
                if(element.id.toString().split("_")[1] == "cnt"){
                    element.textContent = "0";
                    element.textContent = "Start";
                }
            }

            


        }

    }

);




