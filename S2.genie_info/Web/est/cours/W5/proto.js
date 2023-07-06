    function User(n, m) {
         this.name = n;
        this.personne = m;
     }

      function BR (){
          console.log(`Hey my name is ${this.name} and my personne is ${this.personne}`)
      }


      User.prototype.pro1 = BR;


      let u1 = new User("John", "Marry");

      let u2 = new User("Yahyawi", "Boy");

     u1.pro1()