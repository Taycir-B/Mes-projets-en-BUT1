   M S B A M L   `   `   `  ����G  CAnagrammeWPF, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null+clr-namespace:AnagrammeWPFAnagrammeWPF  5   	       AnagrammeWPF.MainWindow   5   	   W SPresentationCore, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   ,localclr-namespace:AnagrammeWPF     5   	   -   5          � Title$  	Anagramme��5   	   $	��450��6   $	��574��6(   .��5	      �  � ColumnDefinitions 5
   
   �� 5      .+�5   
   �� -   5         ��Name$ LBXHistorique��5      $
��Left=�6)   $	��222��6D   $��382,141,0,0q�6Q   $	��Top=�6f   $	��182��6~   �� 5   
   -   5         ��Name$ GBXHistorique��5      $
��Left=�6*   $	��259��6E   $��
Historique��6R   $��382,112,0,0q�6f   $	��Top=�6{   $	��182��6�   �� 5   
   -   5         ��Name$ 
BTNRejouer��5      $��Rejouer��6%   $
��Left=�67   $��26��6R   $��382,384,0,0q�6^   $	��Top=�6s   $��69��6�   6�   �� 5   
   -   5        $ 
BTNQuitter��5      $��Quitter��6%   $
��Left=�67   $��26��6R   $��495,384,0,0q�6^   $	��Top=�6s   $��69��6�   6�   �� 5   
   -   5        $ 	LBXEssais��5      $
��Left=�6%   $	��145��6@   $��
20,279,0,0q�6M   $	��Top=�6a   $	��310��6y   �� 5   
   -   5         ��Name$ 	LBLEssais��5      $��Essais restants :��6#   $
��Left=�6?   $��28��6Z   $��
30,246,0,0q�6f   $	��Top=�6z   $	��101��6�   �� 5   
   -   5        $ 	GBXEssais��5      $
��Left=�6&   $	��198��6A   $��Essais��6N   $��
10,228,0,0q�6^   $	��Top=�6r   $	��338��6�   �� 5   
   -	   5         ��Name$ TXTProposition��5      $
��Left=�6*   $��28��6E   $��
20,157,0,0q�6Q    �� TextWrapping$
 Wrap=�6e   $�� ��6y   $	��Top=�6�   $	��159��6�   �� 5   
   -
   5        $ 	BTNTester��5      $��Tester��6$   $
��Left=�65   $��28��6P   $��198,157,0,0q�6\   $	��Top=�6q   $��89��6�   6�   �� 5   
   -   5        $ GBXProposition��5      $
��Left=�6+   $��92��6F   $��Proposition��6R   $��
10,125,0,0q�6g   $	��Top=�6{   $	��338��6�   �� 5   
   -   5        $ LBLAlphabet��5      $��ALPHABET��6%   $
��Left=�68   $��27��6S   $��	30,65,0,0q�6_   $	��Top=�6r   $	��101��6�   $
��Bold"�6�   �� 5   
   -   5        $ LBLMoteADeviner��5      $��Mot à deviner : ��6)   $
��Left=�6D   $��26��6_   $��	10,34,0,0q�6k   $	��Top=�6~   $	��178��6�   �� 5   
   -   5        $ LBLNbEssais��5      $��5��6%   $
��Left=�61   $��28��6L   $��131,246,0,0q�6X   $	��Top=�6m   $��44��6�   5      5      