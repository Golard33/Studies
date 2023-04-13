location = int ((input  (" mettre le nombre de jour de la location de la voiture ")))
NombreKm = int ((input  (" mettre le nombre de km à parcourir ")))
TarifEssence = (40*location+0.15*NombreKm)
TarifDiesel = (50*location+0.10*NombreKm)

if TarifEssence < TarifDiesel :
    print ((" le tarif essence est le plus avantageux car il coûte") , TarifEssence,("€") ,("alors que le tarif diesel coûte"),  TarifDiesel ,("€"))
else:
    print ((" le tarif diesel est le plus avantageux car il coûte") , TarifDiesel, ("€"),("alors que le tarif essence coûte") , TarifEssence, ("€")) 