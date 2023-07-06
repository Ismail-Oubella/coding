let C = document.getElementById("cel")
let F = document.getElementById("fah")

F.addEventListener('input', () => { 
    let f = Number(F.value)
    C.value = (f - 32) / 1.8
})

C.addEventListener