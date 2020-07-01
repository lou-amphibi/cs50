<? Php
    // configuration
    require ("../ includes / config.php");
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER ["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render ("register_form.php" ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER ["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST ["username"]))
            apologize("Username field is empty");
        if (empty($_POST ["password"]))
            apologize("Password field is empty");
        if (empty($_POST ["confirmation"]))
            apologize("Confirmation field is empty");

        if ($_POST ["password"] != $_POST ["confirmation"])
            apologize("Plase validate password correctly");

        if ( (query ("INSERT INTO users (username, hash, cash) VALUES (?,?, 10000.00)", $ _POST [ "username"], crypt($ _ POST [ "password" ]))===false)
            apologize("Username already use");

        $Rows = query ("SELECT LAST_INSERT_ID () AS id");
        $Id = $rows [0] [ "id"];

        $_SESSION["id"]=$Id;

        redirect("/");
    }
?>