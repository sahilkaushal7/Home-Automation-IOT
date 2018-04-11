<html>
<meta name="viewport" content="width=device-width, initial-scale=1">
<body>

  <head>
        
   <title>IOT</title>
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
color: GREEN;
}

h2 {
    text-align: center;
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
<h1> Command Entered successfully.  </h1>
<h2>
<input type="button" value="Back to Operate Your Appliances" onclick="window.location.href='http://www.myiotprojects.com/ujjwal/update.php'" />
 </h2>
</head>



<?php
   if(isset($_GET['msg1']) || isset($_GET['msg2']) || isset($_GET['msg3']) || isset($_GET['msg4']))
  {
  

	   $dbmsg1 = (string)$_GET['msg1'];
	   $dbmsg2 = (string)$_GET['msg2'];
	   $dbmsg3 = (string)$_GET['msg3'];
	   $dbmsg4 = (string)$_GET['msg4'];
     
   
   
	   echo  $dbmsg1;
	   echo '<br>';
	   echo  $dbmsg2;
	   echo '<br>';
	   echo  $dbmsg3;
	   echo '<br>';
	   echo  $dbmsg4;
	   echo '<br>';
   
   
      	   $myfile = fopen("message.html", "w") or die("Unable to open file!");

           $txt = "IOT";
	   fwrite($myfile, $txt);
//           $txt = "<br>";
//	   fwrite($myfile, $txt);


	   $txt = $dbmsg1;
	   fwrite($myfile, $txt);
	   $txt = ",";
	   fwrite($myfile, $txt);

           
           $txt = $dbmsg2;
	   fwrite($myfile, $txt);
	   $txt = ",";
	   fwrite($myfile, $txt);

           $txt = $dbmsg3;
	   fwrite($myfile, $txt);
	  $txt = ",";
	   fwrite($myfile, $txt);


           $txt = $dbmsg4;
	   fwrite($myfile, $txt);
	   $txt = ",";
	   fwrite($myfile, $txt);


           $txt = "*";
	   fwrite($myfile, $txt);



	   fclose($myfile);
		
   }
   else
   {
       echo "Unable to get variables";
   }
   
 ?>
</body>
</html>