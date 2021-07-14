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

function print(){
    for (let i = 0; i < btnIds.length; i++) {               
        let element = document.getElementById(btnIds[i]);         
        if(element.id.toString().split("_")[1] == "cnt") 
            console.log(`${btnIds[i]}-----------${element.textContent}`);
    }
}

const start = document.getElementById("start").addEventListener("click",
    function enableAllCards() {
        startCount++;
        console.log(startCount);
        
        if (startCount % 2 == 1){
            // To enable all buttons
            this.textContent = "Reset";
            for (var i = 0; i < btnIds.length; i++) {
            
                var element = document.getElementById(btnIds[i]);

                element.className = element.className.split(" ").slice(0, -1).join(" ");
                if(element.id.toString().split("_")[1] == "cnt"){
                    element.textContent = "0";
                }
            }

            // Adding functionality

            // plus
            var easyPlus = document.getElementById("easy_plus").addEventListener("click",
                ()=> {
                    var element = document.getElementById("easy_cnt");
                    var tmpCnt = parseInt(element.textContent) + 1;
                    element.textContent = tmpCnt.toString();
                    console.log(`${element.id}-----${element.textContent}`)
                }
            
            );
            var mediumPlus = document.getElementById("medium_plus").addEventListener("click",
                ()=> {
                    var element = document.getElementById("medium_cnt");
                    var tmpCnt = parseInt(element.textContent) + 1;
                    element.textContent = tmpCnt.toString();
                    console.log(`${element.id}-----${element.textContent}`)
                }
        
            );

            var hardPlus = document.getElementById("hard_plus").addEventListener("click",
                ()=> {
                    var element = document.getElementById("hard_cnt");
                    var tmpCnt = parseInt(element.textContent) + 1;
                    element.textContent = tmpCnt.toString();
                    console.log(`${element.id}-----${element.textContent}`)
                }
        
            );

            // minus
            var easyMinus = document.getElementById("easy_minus").addEventListener("click",
                ()=> {
                    var element = document.getElementById("easy_cnt");
                    if (parseInt(element.textContent) > 0){
                        var tmpCnt = parseInt(element.textContent) - 1;
                        element.textContent = tmpCnt.toString();
                        console.log(`${element.id}-----${element.textContent}`)
                    }
                }
            
            );
            var mediumMinus = document.getElementById("medium_minus").addEventListener("click",
                ()=> {
                    var element = document.getElementById("medium_cnt");
                    if (parseInt(element.textContent) > 0){
                        var tmpCnt = parseInt(element.textContent) - 1;
                        element.textContent = tmpCnt.toString();
                        console.log(`${element.id}-----${element.textContent}`)
                    }
                }
            
            );
            var hardMinus = document.getElementById("hard_minus").addEventListener("click",
                ()=> {
                    var element = document.getElementById("hard_cnt");
                    if (parseInt(element.textContent) > 0){
                        var tmpCnt = parseInt(element.textContent) - 1;
                        element.textContent = tmpCnt.toString();
                        console.log(`${element.id}-----${element.textContent}`)
                    }
                }
            
            );       


        }
        else{
            if (confirm(`Are you sure you want to reset ?`)) {
                location.reload(true);
            }
            else {
                console.log("No Reset...");
                alert("Yah, thats the spirit...");
                startCount--;
            }
            
            // for (var i = 0; i < btnIds.length; i++) {               
            //     var element = document.getElementById(btnIds[i]);         
            //     // to disable the button
            //     const classname = element.className.split(" ")
            //     classname.push("disabled");
            //     element.className = classname.join(" ");
            // }
            
        }
        

        print();
    }

);




