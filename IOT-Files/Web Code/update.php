<html>
<body>

  <head>
             
   <title>Home automation</title>
   <style>
   
   body
   {  
    
    background-color: powderblue;
    
    background-size: 50% 20%;
    background-repeat: no-repeat;
    background-position: center;
    margin-bottom: 100px;
  
    
   }
  
h1 
{
    text-align: center;
color: RED;
}

h2 {
    text-align: left;
     color:maroon;
    
}

h3 {
    text-align: center;
color: green;
     

} 
p
{
 color:blueviolet;
}
}
</style>

   </head>



	<form action="serve.php" method="get">
	
		Appliance 1: <input type="text" name="msg1"><br>
                Appliance 2: <input type="text" name="msg2"><br>
                Appliance 3: <input type="text" name="msg3"><br>
                Appliance 4: <input type="text" name="msg4"><br>

		<input type="submit">
	
	</form>


</body>
</html>