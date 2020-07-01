<?php

    // configuration
    require("../includes/config.php");

    $rows = query("SELECT symbol, shares FROM stock WHERE id = ?", $_SESSION["id"]);

    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
            ];
        }
    }

    $cash=query("SELECT cash FROM users where id = ?", $_SESSION["id"]);
    $cash=$cash[0]["cash"];

    // render portfolio
    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio"]);

?>
