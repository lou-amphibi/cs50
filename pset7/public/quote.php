<? Php
    require("../includes/config.php");

    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("quote_form.php", ["title" => "Get Quote"]);
    }

    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $Stock = lookup ($_POST ["symbol"]);

        if($Stock==false)
        {
            apologoze("Uncorrectly symbol");
        }
        else
	    {
	        render("quote_display.php", ["title" => "Quote", "stock" => $Stock]);
	    }

    }
?>